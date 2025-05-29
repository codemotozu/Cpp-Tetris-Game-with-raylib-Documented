/// Position Class Implementation
/// 
/// Simple coordinate class implementation for the C++ Tetris game using row and column positioning. // Einfache Koordinaten-Klassen-Implementierung für das C++ Tetris-Spiel mit Zeilen- und Spaltenpositionierung.
/// Represents a single cell position within the Tetris grid using integer coordinates. // Repräsentiert eine einzelne Zellposition innerhalb des Tetris-Rasters mit Ganzzahl-Koordinaten.
/// 
/// Usage:
/// ```cpp
/// #include "position.h"
/// 
/// // Create position at row 5, column 3
/// Position blockCell(5, 3);
/// 
/// // Access coordinates
/// int currentRow = blockCell.row;
/// int currentCol = blockCell.column;
/// 
/// // Use in vectors for block shapes
/// std::vector<Position> blockShape = {
///     Position(0, 0), Position(0, 1),
///     Position(1, 0), Position(1, 1)
/// };
/// ```
/// 
/// EN: Provides a simple coordinate system for representing cell positions in the Tetris grid with integer-based row/column indexing.
/// DE: Bietet ein einfaches Koordinatensystem zur Darstellung von Zellpositionen im Tetris-Raster mit ganzzahlbasierter Zeilen-/Spalten-Indizierung.

#include "position.h" // Includes the Position class header file with class declaration and member variable definitions. // Inkludiert die Position-Klassen-Header-Datei mit Klassendeklaration und Mitgliedsvariablen-Definitionen.

Position::Position(int row, int column) // Constructor that initializes a new Position object with specified row and column coordinates. // Konstruktor, der ein neues Position-Objekt mit angegebenen Zeilen- und Spalten-Koordinaten initialisiert.
{
    this->row = row; // Sets the row member variable to the provided row parameter value. // Setzt die Zeilen-Mitgliedsvariable auf den bereitgestellten Zeilen-Parameterwert.
    // Uses 'this->' pointer to explicitly reference the object's member variable. // Verwendet 'this->' Zeiger, um explizit auf die Mitgliedsvariable des Objekts zu verweisen.
    this->column = column; // Sets the column member variable to the provided column parameter value. // Setzt die Spalten-Mitgliedsvariable auf den bereitgestellten Spalten-Parameterwert.
    // Ensures clear distinction between parameter and member variable with same name. // Stellt klare Unterscheidung zwischen Parameter und Mitgliedsvariable mit gleichem Namen sicher.
}
