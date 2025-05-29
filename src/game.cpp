/// Game Class Implementation
/// 
/// Core game logic implementation for the C++ Tetris game using raylib graphics and audio library. // Kern-Spiellogik-Implementierung für das C++ Tetris-Spiel mit raylib-Grafik- und Audio-Bibliothek.
/// Manages game state, block movement, collision detection, scoring, and audio playback. // Verwaltet Spielzustand, Blockbewegung, Kollisionserkennung, Punktevergabe und Audio-Wiedergabe.
/// 
/// Usage:
/// ```cpp
/// Game tetrisGame;
/// 
/// while (!WindowShouldClose()) {
///     tetrisGame.HandleInput();
///     tetrisGame.MoveBlockDown();
///     
///     BeginDrawing();
///     tetrisGame.Draw();
///     EndDrawing();
/// }
/// ```
/// 
/// EN: Implements complete Tetris game mechanics including block generation, movement, line clearing, and game-over detection.
/// DE: Implementiert vollständige Tetris-Spielmechanik einschließlich Blockgenerierung, Bewegung, Linienräumung und Game-Over-Erkennung.

#include "game.h" // Includes the Game class header file with method declarations. // Inkludiert die Game-Klassen-Header-Datei mit Methodendeklarationen.
#include <random> // Includes random number generation utilities for block selection. // Inkludiert Zufallszahlengenerierungs-Hilfsfunktionen für Blockauswahl.

Game::Game() // Constructor that initializes a new Tetris game instance. // Konstruktor, der eine neue Tetris-Spielinstanz initialisiert.
{
    grid = Grid(); // Initializes the game grid (20x10 Tetris playing field). // Initialisiert das Spielfeld (20x10 Tetris-Spielbereich).
    blocks = GetAllBlocks(); // Creates vector containing all seven Tetris block types. // Erstellt Vektor mit allen sieben Tetris-Blocktypen.
    currentBlock = GetRandomBlock(); // Selects and removes a random block from the pool for current play. // Wählt und entfernt einen zufälligen Block aus dem Pool für aktuelles Spiel.
    nextBlock = GetRandomBlock(); // Selects and removes another random block for the next piece preview. // Wählt und entfernt einen weiteren zufälligen Block für die nächste Blockvorschau.
    gameOver = false; // Initializes game state as active (not game over). // Initialisiert Spielzustand als aktiv (kein Game Over).
    score = 0; // Initializes player score to zero points. // Initialisiert Spielerpunktzahl auf null Punkte.
    InitAudioDevice(); // Initializes raylib audio system for music and sound effects. // Initialisiert raylib-Audiosystem für Musik und Soundeffekte.
    music = LoadMusicStream("Sounds/music.mp3"); // Loads background music file from disk into memory. // Lädt Hintergrundmusik-Datei von der Festplatte in den Speicher.
    PlayMusicStream(music); // Starts playing the background music in a loop. // Startet die Wiedergabe der Hintergrundmusik in einer Schleife.
    rotateSound = LoadSound("Sounds/rotate.mp3"); // Loads rotation sound effect for block rotations. // Lädt Rotationsgeräusch für Blockrotationen.
    clearSound = LoadSound("Sounds/clear.mp3"); // Loads line-clear sound effect for completed rows. // Lädt Linienräumungsgeräusch für abgeschlossene Reihen.
}

Game::~Game() // Destructor that cleans up resources when Game object is destroyed. // Destruktor, der Ressourcen bereinigt, wenn das Game-Objekt zerstört wird.
{
    UnloadSound(rotateSound); // Frees memory used by rotation sound effect. // Gibt Speicher frei, der von Rotationsgeräusch verwendet wurde.
    UnloadSound(clearSound); // Frees memory used by line-clear sound effect. // Gibt Speicher frei, der von Linienräumungsgeräusch verwendet wurde.
    UnloadMusicStream(music); // Frees memory used by background music stream. // Gibt Speicher frei, der von Hintergrundmusik-Stream verwendet wurde.
    CloseAudioDevice(); // Shuts down raylib audio system and releases audio resources. // Schließt raylib-Audiosystem und gibt Audio-Ressourcen frei.
}

Block Game::GetRandomBlock() // Returns a random block from the available pool, refilling when empty. // Gibt einen zufälligen Block aus dem verfügbaren Pool zurück, füllt nach, wenn leer.
{
    if (blocks.empty()) // Checks if the block pool is empty (all blocks used). // Prüft, ob der Block-Pool leer ist (alle Blöcke verwendet).
    {
        blocks = GetAllBlocks(); // Refills the pool with all seven block types for fair distribution. // Füllt den Pool mit allen sieben Blocktypen für faire Verteilung.
    }
    int randomIndex = rand() % blocks.size(); // Generates random index within the range of available blocks. // Generiert zufälligen Index im Bereich der verfügbaren Blöcke.
    Block block = blocks[randomIndex]; // Retrieves the block at the randomly selected index. // Ruft den Block am zufällig ausgewählten Index ab.
    blocks.erase(blocks.begin() + randomIndex); // Removes the selected block from pool to prevent duplicates. // Entfernt den ausgewählten Block aus dem Pool, um Duplikate zu verhindern.
    return block; // Returns the randomly selected block for use in game. // Gibt den zufällig ausgewählten Block zur Verwendung im Spiel zurück.
}

std::vector<Block> Game::GetAllBlocks() // Creates and returns a vector containing all seven Tetris block types. // Erstellt und gibt einen Vektor mit allen sieben Tetris-Blocktypen zurück.
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()}; // Returns vector with instances of all Tetris pieces (I, J, L, O, S, T, Z). // Gibt Vektor mit Instanzen aller Tetris-Stücke zurück (I, J, L, O, S, T, Z).
}

void Game::Draw() // Renders all game elements to the screen using raylib drawing functions. // Rendert alle Spielelemente auf den Bildschirm mit raylib-Zeichenfunktionen.
{
    grid.Draw(); // Draws the main game grid with all placed blocks. // Zeichnet das Hauptspielfeld mit allen platzierten Blöcken.
    currentBlock.Draw(11, 11); // Draws the currently falling block with 11-pixel offset for grid positioning. // Zeichnet den aktuell fallenden Block mit 11-Pixel-Offset für Rasterpositionierung.
    switch (nextBlock.id) // Determines drawing position based on next block type for proper preview alignment. // Bestimmt Zeichenposition basierend auf nächstem Blocktyp für ordnungsgemäße Vorschau-Ausrichtung.
    {
    case 3: // Special positioning for I-block (straight line piece). // Spezielle Positionierung für I-Block (gerade Linie).
        nextBlock.Draw(255, 290); // Draws I-block at adjusted position to center it in preview area. // Zeichnet I-Block an angepasster Position, um ihn im Vorschaubereich zu zentrieren.
        break;
    case 4: // Special positioning for O-block (square piece). // Spezielle Positionierung für O-Block (quadratisches Stück).
        nextBlock.Draw(255, 280); // Draws O-block at slightly higher position for better visual alignment. // Zeichnet O-Block an etwas höherer Position für bessere visuelle Ausrichtung.
        break;
    default: // Default positioning for all other block types (L, J, S, T, Z). // Standard-Positionierung für alle anderen Blocktypen (L, J, S, T, Z).
        nextBlock.Draw(270, 270); // Draws other blocks at standard preview position. // Zeichnet andere Blöcke an Standard-Vorschau-Position.
        break;
    }
}

void Game::HandleInput() // Processes keyboard input and executes corresponding game actions. // Verarbeitet Tastatureingaben und führt entsprechende Spielaktionen aus.
{
    int keyPressed = GetKeyPressed(); // Gets the currently pressed key code from raylib input system. // Holt den aktuell gedrückten Tastencode vom raylib-Eingabesystem.
    if (gameOver && keyPressed != 0) // Checks if game is over and any key was pressed to restart. // Prüft, ob Spiel vorbei ist und eine Taste zum Neustart gedrückt wurde.
    {
        gameOver = false; // Resets game over state to resume gameplay. // Setzt Game-Over-Zustand zurück, um Spiel fortzusetzen.
        Reset(); // Resets all game elements to initial state for new game. // Setzt alle Spielelemente auf Anfangszustand für neues Spiel zurück.
    }
    switch (keyPressed) // Executes different actions based on which key was pressed. // Führt verschiedene Aktionen basierend auf gedrückter Taste aus.
    {
    case KEY_LEFT: // Left arrow key pressed - move block left. // Linke Pfeiltaste gedrückt - Block nach links bewegen.
        MoveBlockLeft(); // Attempts to move current block one column to the left. // Versucht, aktuellen Block eine Spalte nach links zu bewegen.
        break;
    case KEY_RIGHT: // Right arrow key pressed - move block right. // Rechte Pfeiltaste gedrückt - Block nach rechts bewegen.
        MoveBlockRight(); // Attempts to move current block one column to the right. // Versucht, aktuellen Block eine Spalte nach rechts zu bewegen.
        break;
    case KEY_DOWN: // Down arrow key pressed - move block down faster. // Pfeil-nach-unten-Taste gedrückt - Block schneller nach unten bewegen.
        MoveBlockDown(); // Forces current block to move down one row. // Zwingt aktuellen Block, sich eine Reihe nach unten zu bewegen.
        UpdateScore(0, 1); // Awards 1 point for manual downward movement. // Vergibt 1 Punkt für manuelle Abwärtsbewegung.
        break;
    case KEY_UP: // Up arrow key pressed - rotate block clockwise. // Pfeil-nach-oben-Taste gedrückt - Block im Uhrzeigersinn drehen.
        RotateBlock(); // Attempts to rotate current block to next rotation state. // Versucht, aktuellen Block zum nächsten Rotationszustand zu drehen.
        break;
    }
}

void Game::MoveBlockLeft() // Moves the current block one column to the left with collision checking. // Bewegt den aktuellen Block eine Spalte nach links mit Kollisionsprüfung.
{
    if (!gameOver) // Only allows movement if game is not over. // Erlaubt Bewegung nur, wenn Spiel nicht vorbei ist.
    {
        currentBlock.Move(0, -1); // Moves block left by decrementing column position. // Bewegt Block nach links durch Verringern der Spaltenposition.
        if (IsBlockOutside() || BlockFits() == false) // Checks if move causes collision or goes out of bounds. // Prüft, ob Bewegung Kollision verursacht oder Grenzen überschreitet.
        {
            currentBlock.Move(0, 1); // Reverts the move by moving block back to original position. // Macht Bewegung rückgängig, indem Block zur ursprünglichen Position zurückbewegt wird.
        }
    }
}

void Game::MoveBlockRight() // Moves the current block one column to the right with collision checking. // Bewegt den aktuellen Block eine Spalte nach rechts mit Kollisionsprüfung.
{
    if (!gameOver) // Only allows movement if game is not over. // Erlaubt Bewegung nur, wenn Spiel nicht vorbei ist.
    {
        currentBlock.Move(0, 1); // Moves block right by incrementing column position. // Bewegt Block nach rechts durch Erhöhen der Spaltenposition.
        if (IsBlockOutside() || BlockFits() == false) // Checks if move causes collision or goes out of bounds. // Prüft, ob Bewegung Kollision verursacht oder Grenzen überschreitet.
        {
            currentBlock.Move(0, -1); // Reverts the move by moving block back to original position. // Macht Bewegung rückgängig, indem Block zur ursprünglichen Position zurückbewegt wird.
        }
    }
}

void Game::MoveBlockDown() // Moves the current block one row down or locks it if it can't move. // Bewegt den aktuellen Block eine Reihe nach unten oder sperrt ihn, wenn er sich nicht bewegen kann.
{
    if (!gameOver) // Only allows movement if game is not over. // Erlaubt Bewegung nur, wenn Spiel nicht vorbei ist.
    {
        currentBlock.Move(1, 0); // Moves block down by incrementing row position. // Bewegt Block nach unten durch Erhöhen der Reihenposition.
        if (IsBlockOutside() || BlockFits() == false) // Checks if downward move causes collision or boundary violation. // Prüft, ob Abwärtsbewegung Kollision oder Grenzverletzung verursacht.
        {
            currentBlock.Move(-1, 0); // Reverts downward movement to previous valid position. // Macht Abwärtsbewegung zur vorherigen gültigen Position rückgängig.
            LockBlock(); // Locks the block in place and handles line clearing and game over detection. // Sperrt den Block an Ort und Stelle und behandelt Linienräumung und Game-Over-Erkennung.
        }
    }
}

bool Game::IsBlockOutside() // Checks if any part of the current block is outside the game grid boundaries. // Prüft, ob irgendein Teil des aktuellen Blocks außerhalb der Spielfeld-Grenzen ist.
{
    std::vector<Position> tiles = currentBlock.GetCellPositions(); // Gets all cell positions that make up the current block. // Holt alle Zellpositionen, die den aktuellen Block bilden.
    for (Position item : tiles) // Iterates through each cell position in the block. // Iteriert durch jede Zellposition im Block.
    {
        if (grid.IsCellOutside(item.row, item.column)) // Checks if this cell position is outside grid boundaries. // Prüft, ob diese Zellposition außerhalb der Rastergrenzen ist.
        {
            return true; // Returns true if any cell is outside valid grid area. // Gibt wahr zurück, wenn irgendeine Zelle außerhalb des gültigen Rasterbereichs ist.
        }
    }
    return false; // Returns false if all cells are within valid grid boundaries. // Gibt falsch zurück, wenn alle Zellen innerhalb gültiger Rastergrenzen sind.
}

void Game::RotateBlock() // Rotates the current block clockwise with collision and boundary checking. // Rotiert den aktuellen Block im Uhrzeigersinn mit Kollisions- und Grenzprüfung.
{
    if (!gameOver) // Only allows rotation if game is not over. // Erlaubt Rotation nur, wenn Spiel nicht vorbei ist.
    {
        currentBlock.Rotate(); // Rotates block to its next rotation state. // Rotiert Block zu seinem nächsten Rotationszustand.
        if (IsBlockOutside() || BlockFits() == false) // Checks if rotation causes collision or boundary violation. // Prüft, ob Rotation Kollision oder Grenzverletzung verursacht.
        {
            currentBlock.UndoRotation(); // Reverts rotation back to previous valid state. // Macht Rotation zum vorherigen gültigen Zustand rückgängig.
        }
        else // Rotation was successful and valid. // Rotation war erfolgreich und gültig.
        {
            PlaySound(rotateSound); // Plays rotation sound effect to provide audio feedback. // Spielt Rotationsgeräusch ab, um Audio-Feedback zu geben.
        }
    }
}

void Game::LockBlock() // Locks the current block in place and handles game progression logic. // Sperrt den aktuellen Block an Ort und Stelle und behandelt Spielfortschrittslogik.
{
    std::vector<Position> tiles = currentBlock.GetCellPositions(); // Gets all cell positions of the block to be locked. // Holt alle Zellpositionen des zu sperrenden Blocks.
    for (Position item : tiles) // Iterates through each cell position in the block. // Iteriert durch jede Zellposition im Block.
    {
        grid.grid[item.row][item.column] = currentBlock.id; // Places block's ID in grid at each cell position. // Platziert Block-ID im Raster an jeder Zellposition.
    }
    currentBlock = nextBlock; // Makes the next block become the current falling block. // Macht den nächsten Block zum aktuell fallenden Block.
    if (BlockFits() == false) // Checks if new current block fits at spawn position. // Prüft, ob neuer aktueller Block an Spawn-Position passt.
    {
        gameOver = true; // Sets game over state if new block cannot fit (grid is full). // Setzt Game-Over-Zustand, wenn neuer Block nicht passt (Raster ist voll).
    }
    nextBlock = GetRandomBlock(); // Generates a new random block for the next piece preview. // Generiert einen neuen zufälligen Block für die nächste Blockvorschau.
    int rowsCleared = grid.ClearFullRows(); // Attempts to clear any completed rows and returns count. // Versucht, vollständige Reihen zu räumen und gibt Anzahl zurück.
    if (rowsCleared > 0) // Checks if any rows were successfully cleared. // Prüft, ob irgendwelche Reihen erfolgreich geräumt wurden.
    {
        PlaySound(clearSound); // Plays line-clear sound effect for audio feedback. // Spielt Linienräumungsgeräusch für Audio-Feedback ab.
        UpdateScore(rowsCleared, 0); // Updates score based on number of rows cleared. // Aktualisiert Punktzahl basierend auf Anzahl geräumter Reihen.
    }
}

bool Game::BlockFits() // Checks if the current block can fit at its current position without collision. // Prüft, ob der aktuelle Block an seiner aktuellen Position ohne Kollision passen kann.
{
    std::vector<Position> tiles = currentBlock.GetCellPositions(); // Gets all cell positions that make up the current block. // Holt alle Zellpositionen, die den aktuellen Block bilden.
    for (Position item : tiles) // Iterates through each cell position in the block. // Iteriert durch jede Zellposition im Block.
    {
        if (grid.IsCellEmpty(item.row, item.column) == false) // Checks if grid cell at this position is already occupied. // Prüft, ob Rasterzelle an dieser Position bereits belegt ist.
        {
            return false; // Returns false if any cell position is occupied (collision detected). // Gibt falsch zurück, wenn irgendeine Zellposition belegt ist (Kollision erkannt).
        }
    }
    return true; // Returns true if all cell positions are empty (block fits). // Gibt wahr zurück, wenn alle Zellpositionen leer sind (Block passt).
}

void Game::Reset() // Resets all game elements to initial state for starting a new game. // Setzt alle Spielelemente auf Anfangszustand für ein neues Spiel zurück.
{
    grid.Initialize(); // Clears the game grid by setting all cells to empty state. // Räumt das Spielfeld durch Setzen aller Zellen auf leeren Zustand.
    blocks = GetAllBlocks(); // Refills block pool with all seven Tetris piece types. // Füllt Block-Pool mit allen sieben Tetris-Stücktypen.
    currentBlock = GetRandomBlock(); // Selects new random block for current play. // Wählt neuen zufälligen Block für aktuelles Spiel.
    nextBlock = GetRandomBlock(); // Selects new random block for next piece preview. // Wählt neuen zufälligen Block für nächste Blockvorschau.
    score = 0; // Resets player score back to zero points. // Setzt Spielerpunktzahl auf null Punkte zurück.
}

void Game::UpdateScore(int linesCleared, int moveDownPoints) // Updates the player's score based on lines cleared and manual movements. // Aktualisiert die Spielerpunktzahl basierend auf geräumten Linien und manuellen Bewegungen.
{
    switch (linesCleared) // Awards different point values based on number of lines cleared simultaneously. // Vergibt verschiedene Punktwerte basierend auf gleichzeitig geräumten Linien.
    {
    case 1: // Single line clear (Tetris terminology: "Single"). // Einzellinienräumung (Tetris-Terminologie: "Single").
        score += 100; // Awards 100 points for clearing one row. // Vergibt 100 Punkte für das Räumen einer Reihe.
        break;
    case 2: // Double line clear (Tetris terminology: "Double"). // Doppellinienräumung (Tetris-Terminologie: "Double").
        score += 300; // Awards 300 points for clearing two rows simultaneously. // Vergibt 300 Punkte für das gleichzeitige Räumen von zwei Reihen.
        break;
    case 3: // Triple line clear (Tetris terminology: "Triple"). // Dreifachlinienräumung (Tetris-Terminologie: "Triple").
        score += 500; // Awards 500 points for clearing three rows simultaneously. // Vergibt 500 Punkte für das gleichzeitige Räumen von drei Reihen.
        break;
    default: // No lines cleared or four lines (Tetris) - no additional points here. // Keine Linien geräumt oder vier Linien (Tetris) - keine zusätzlichen Punkte hier.
        break; // Note: Four-line clears could be handled with additional case. // Hinweis: Vierfach-Linienräumungen könnten mit zusätzlichem Fall behandelt werden.
    }

    score += moveDownPoints; // Adds points for manual downward block movements (soft drop). // Fügt Punkte für manuelle Abwärtsblockbewegungen hinzu (Soft Drop).
}
