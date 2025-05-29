/// Block Class Implementation
/// 
/// Core block class for the C++ Tetris game using raylib graphics library. // Kern-Block-Klasse für das C++ Tetris-Spiel mit der raylib-Grafikbibliothek.
/// Handles block rendering, movement, rotation, and position management. // Verwaltet Block-Rendering, Bewegung, Rotation und Positionsverwaltung.
/// 
/// Usage:
/// ```cpp
/// Block myBlock;
/// myBlock.Draw(offsetX, offsetY);
/// myBlock.Move(1, 0); // Move down one row
/// myBlock.Rotate();
/// ```
/// 
/// EN: Provides fundamental block functionality including drawing, movement, rotation, and collision detection support.
/// DE: Bietet grundlegende Block-Funktionalität einschließlich Zeichnen, Bewegung, Rotation und Kollisionserkennung.

#include "block.h" // Includes the Block class header file with declarations. // Inkludiert die Block-Klassen-Header-Datei mit Deklarationen.

Block::Block() // Default constructor that initializes a new Block instance. // Standard-Konstruktor, der eine neue Block-Instanz initialisiert.
{
    cellSize = 30; // Sets the size of each cell in pixels (30x30). // Setzt die Größe jeder Zelle in Pixeln (30x30).
    rotationState = 0; // Initializes rotation state to 0 (first rotation). // Initialisiert den Rotationszustand auf 0 (erste Rotation).
    colors = GetCellColors(); // Gets the color palette for rendering blocks. // Holt die Farbpalette zum Rendern der Blöcke.
    rowOffset = 0; // Initializes vertical position offset to 0. // Initialisiert den vertikalen Positions-Offset auf 0.
    columnOffset = 0; // Initializes horizontal position offset to 0. // Initialisiert den horizontalen Positions-Offset auf 0.
}

void Block::Draw(int offsetX, int offsetY) // Renders the block on screen with given offsets. // Rendert den Block auf dem Bildschirm mit gegebenen Offsets.
{
    std::vector<Position> tiles = GetCellPositions(); // Gets all cell positions for the current block. // Holt alle Zellpositionen für den aktuellen Block.
    for (Position item : tiles) // Iterates through each cell position in the block. // Iteriert durch jede Zellposition im Block.
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]); 
        // Draws a rectangle for each cell using raylib's DrawRectangle function. // Zeichnet ein Rechteck für jede Zelle mit raylibsBildschirm DrawRectangle-Funktion.
        // Parameters: x-position, y-position, width, height, color. // Parameter: x-Position, y-Position, Breite, Höhe, Farbe.
        // cellSize - 1 creates a small gap between cells for visual separation. // cellSize - 1 erzeugt eine kleine Lücke zwischen Zellen für visuelle Trennung.
    }
}

void Block::Move(int rows, int columns) // Moves the block by specified number of rows and columns. // Bewegt den Block um die angegebene Anzahl von Zeilen und Spalten.
{
    rowOffset += rows; // Adds the row movement to current row offset. // Addiert die Zeilenbewegung zum aktuellen Zeilen-Offset.
    columnOffset += columns; // Adds the column movement to current column offset. // Addiert die Spaltenbewegung zum aktuellen Spalten-Offset.
}

std::vector<Position> Block::GetCellPositions() // Returns the actual positions of all cells in the block. // Gibt die tatsächlichen Positionen aller Zellen im Block zurück.
{
    std::vector<Position> tiles = cells[rotationState]; // Gets the cell pattern for current rotation state. // Holt das Zellmuster für den aktuellen Rotationszustand.
    std::vector<Position> movedTiles; // Creates vector to store adjusted positions. // Erstellt Vektor zum Speichern angepasster Positionen.
    for (Position item : tiles) // Iterates through each cell in the current rotation. // Iteriert durch jede Zelle in der aktuellen Rotation.
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset); // Creates new position by adding offsets. // Erstellt neue Position durch Hinzufügen von Offsets.
        movedTiles.push_back(newPos); // Adds the adjusted position to the result vector. // Fügt die angepasste Position zum Ergebnis-Vektor hinzu.
    }
    return movedTiles; // Returns vector containing all adjusted cell positions. // Gibt Vektor mit allen angepassten Zellpositionen zurück.
}

void Block::Rotate() // Rotates the block to its next rotation state. // Rotiert den Block zum nächsten Rotationszustand.
{
    rotationState++; // Increments the rotation state counter. // Erhöht den Rotationszustand-Zähler.
    if (rotationState == (int)cells.size()) // Checks if rotation state exceeds available rotations. // Prüft, ob der Rotationszustand verfügbare Rotationen überschreitet.
    {
        rotationState = 0; // Resets to first rotation state (circular rotation). // Setzt auf ersten Rotationszustand zurück (zirkuläre Rotation).
    }
}

void Block::UndoRotation() // Reverses the last rotation (used for collision handling). // Macht die letzte Rotation rückgängig (für Kollisionsbehandlung verwendet).
{
    rotationState--; // Decrements the rotation state counter. // Verringert den Rotationszustand-Zähler.
    if (rotationState == -1) // Checks if rotation state becomes negative. // Prüft, ob der Rotationszustand negativ wird.
    {
        rotationState = cells.size() - 1; // Sets to last rotation state (circular rotation). // Setzt auf letzten Rotationszustand (zirkuläre Rotation).
    }
}
