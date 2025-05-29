/// Game Class Header
/// 
/// Header file declaring the Game class interface for the C++ Tetris game using raylib. // Header-Datei, die die Game-Klassen-Schnittstelle für das C++ Tetris-Spiel mit raylib deklariert.
/// Defines the complete Tetris game controller with all methods and data members for game logic. // Definiert den vollständigen Tetris-Spiel-Controller mit allen Methoden und Datenmitgliedern für Spiellogik.
/// 
/// Usage:
/// ```cpp
/// #include "game.h"
/// 
/// Game tetrisGame;
/// tetrisGame.HandleInput();
/// tetrisGame.MoveBlockDown();
/// 
/// BeginDrawing();
/// tetrisGame.Draw();
/// EndDrawing();
/// ```
/// 
/// EN: Declares the main game controller class that manages all Tetris gameplay mechanics, rendering, and state.
/// DE: Deklariert die Hauptspiel-Controller-Klasse, die alle Tetris-Spielmechaniken, Rendering und Zustand verwaltet.

#pragma once // Ensures this header file is included only once during compilation to prevent duplicate definitions. // Stellt sicher, dass diese Header-Datei nur einmal während der Kompilierung eingebunden wird, um doppelte Definitionen zu verhindern.
#include "grid.h" // Includes the Grid class header for the game playing field (20x10 Tetris grid). // Inkludiert die Grid-Klassen-Header für das Spielfeld (20x10 Tetris-Raster).
#include "blocks.cpp" // Includes all Tetris block class implementations (I, J, L, O, S, T, Z blocks). // Inkludiert alle Tetris-Block-Klassen-Implementierungen (I, J, L, O, S, T, Z-Blöcke).

class Game // Declares the Game class that serves as the main controller for Tetris gameplay. // Deklariert die Game-Klasse, die als Hauptcontroller für Tetris-Gameplay dient.
{
public: // Public interface accessible from outside the class for external game control. // Öffentliche Schnittstelle, die von außerhalb der Klasse für externe Spielsteuerung zugänglich ist.
    Game(); // Constructor declaration that initializes a new Tetris game instance. // Konstruktor-Deklaration, die eine neue Tetris-Spielinstanz initialisiert.
    ~Game(); // Destructor declaration that cleans up resources when game object is destroyed. // Destruktor-Deklaration, die Ressourcen bereinigt, wenn das Spielobjekt zerstört wird.
    void Draw(); // Method declaration for rendering all game elements to the screen. // Methoden-Deklaration zum Rendern aller Spielelemente auf den Bildschirm.
    void HandleInput(); // Method declaration for processing keyboard input and executing game actions. // Methoden-Deklaration zur Verarbeitung von Tastatureingaben und Ausführung von Spielaktionen.
    void MoveBlockDown(); // Method declaration for moving the current block down one row (automatic or manual). // Methoden-Deklaration zum Bewegen des aktuellen Blocks eine Reihe nach unten (automatisch oder manuell).
    bool gameOver; // Public boolean flag indicating whether the game has ended (true = game over). // Öffentliche boolesche Flagge, die anzeigt, ob das Spiel beendet ist (true = Game Over).
    int score; // Public integer storing the player's current score points. // Öffentliche Ganzzahl, die die aktuellen Punkte des Spielers speichert.
    Music music; // Public Music object for background music stream (raylib audio type). // Öffentliches Music-Objekt für Hintergrundmusik-Stream (raylib-Audio-Typ).

private: // Private members accessible only within the Game class for internal game logic. // Private Mitglieder, die nur innerhalb der Game-Klasse für interne Spiellogik zugänglich sind.
    void MoveBlockLeft(); // Private method declaration for moving current block one column to the left. // Private Methoden-Deklaration zum Bewegen des aktuellen Blocks eine Spalte nach links.
    void MoveBlockRight(); // Private method declaration for moving current block one column to the right. // Private Methoden-Deklaration zum Bewegen des aktuellen Blocks eine Spalte nach rechts.
    Block GetRandomBlock(); // Private method declaration that returns a random block from the available pool. // Private Methoden-Deklaration, die einen zufälligen Block aus dem verfügbaren Pool zurückgibt.
    std::vector<Block> GetAllBlocks(); // Private method declaration that creates a vector containing all seven Tetris block types. // Private Methoden-Deklaration, die einen Vektor mit allen sieben Tetris-Blocktypen erstellt.
    bool IsBlockOutside(); // Private method declaration that checks if current block is outside grid boundaries. // Private Methoden-Deklaration, die prüft, ob der aktuelle Block außerhalb der Rastergrenzen ist.
    void RotateBlock(); // Private method declaration for rotating the current block clockwise with collision checking. // Private Methoden-Deklaration zum Rotieren des aktuellen Blocks im Uhrzeigersinn mit Kollisionsprüfung.
    void LockBlock(); // Private method declaration for locking current block in place and handling line clearing. // Private Methoden-Deklaration zum Sperren des aktuellen Blocks an Ort und Stelle und Behandlung der Linienräumung.
    bool BlockFits(); // Private method declaration that checks if current block fits at its position without collision. // Private Methoden-Deklaration, die prüft, ob der aktuelle Block an seiner Position ohne Kollision passt.
    void Reset(); // Private method declaration for resetting all game elements to initial state for new game. // Private Methoden-Deklaration zum Zurücksetzen aller Spielelemente auf Anfangszustand für neues Spiel.
    void UpdateScore(int linesCleared, int moveDownPoints); // Private method declaration for updating score based on lines cleared and movements. // Private Methoden-Deklaration zur Aktualisierung der Punktzahl basierend auf geräumten Linien und Bewegungen.
    Grid grid; // Private Grid object representing the 20x10 Tetris playing field. // Privates Grid-Objekt, das das 20x10 Tetris-Spielfeld repräsentiert.
    std::vector<Block> blocks; // Private vector containing the pool of available blocks for fair distribution. // Privater Vektor mit dem Pool verfügbarer Blöcke für faire Verteilung.
    Block currentBlock; // Private Block object representing the currently falling Tetris piece. // Privates Block-Objekt, das das aktuell fallende Tetris-Stück repräsentiert.
    Block nextBlock; // Private Block object representing the next piece shown in the preview area. // Privates Block-Objekt, das das nächste Stück im Vorschaubereich repräsentiert.
    Sound rotateSound; // Private Sound object for rotation sound effect (raylib audio type). // Privates Sound-Objekt für Rotationsgeräusch-Effekt (raylib-Audio-Typ).
    Sound clearSound; // Private Sound object for line-clear sound effect (raylib audio type). // Privates Sound-Objekt für Linienräumungsgeräusch-Effekt (raylib-Audio-Typ).
};
