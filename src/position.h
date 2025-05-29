/// Position Class Header
/// 
/// Header file declaring the Position class interface for the C++ Tetris game coordinate system. // Header-Datei, die die Position-Klassen-Schnittstelle für das C++ Tetris-Spiel-Koordinatensystem deklariert.
/// Defines a simple coordinate class for representing cell positions within the Tetris grid using row/column indexing. // Definiert eine einfache Koordinaten-Klasse zur Darstellung von Zellpositionen innerhalb des Tetris-Rasters mit Zeilen-/Spalten-Indizierung.
/// 
/// Usage:
/// ```cpp
/// #include "position.h"
/// 
/// // Create a position at row 3, column 5
/// Position cellPos(3, 5);
/// 
/// // Access coordinates directly
/// int currentRow = cellPos.row;
/// int currentCol = cellPos.column;
/// 
/// // Use in block shape definitions
/// std::vector<Position> lBlockShape = {
///     Position(0, 2), Position(1, 0), 
///     Position(1, 1), Position(1, 2)
/// };
/// 
/// // Check position values
/// if (cellPos.row >= 0 && cellPos.column >= 0) {
///     // Valid grid position
/// }
/// ```
/// 
/// EN: Provides a lightweight coordinate class for managing 2D grid positions in the Tetris game with direct member access.
/// DE: Bietet eine leichtgewichtige Koordinaten-Klasse zur Verwaltung von 2D-Raster-Positionen im Tetris-Spiel mit direktem Mitgliederzugriff.

#pragma once // Ensures this header file is included only once during compilation to prevent duplicate definitions. // Stellt sicher, dass diese Header-Datei nur einmal während der Kompilierung eingebunden wird, um doppelte Definitionen zu verhindern.

class Position // Declares the Position class that represents a coordinate pair (row, column) in the Tetris grid. // Deklariert die Position-Klasse, die ein Koordinatenpaar (Zeile, Spalte) im Tetris-Raster repräsentiert.
{
public: // Public interface accessible from outside the class for direct coordinate access and manipulation. // Öffentliche Schnittstelle, die von außerhalb der Klasse für direkten Koordinatenzugriff und -manipulation zugänglich ist.
    Position(int row, int column); // Constructor declaration that initializes a Position object with specified row and column coordinates. // Konstruktor-Deklaration, die ein Position-Objekt mit angegebenen Zeilen- und Spalten-Koordinaten initialisiert.
    // Parameters: row (vertical position, 0-19 in standard Tetris), column (horizontal position, 0-9 in standard Tetris). // Parameter: Zeile (vertikale Position, 0-19 im Standard-Tetris), Spalte (horizontale Position, 0-9 im Standard-Tetris).
    int row; // Public integer member variable storing the vertical coordinate (row index in the grid). // Öffentliche Ganzzahl-Mitgliedsvariable, die die vertikale Koordinate speichert (Zeilen-Index im Raster).
    int column; // Public integer member variable storing the horizontal coordinate (column index in the grid). // Öffentliche Ganzzahl-Mitgliedsvariable, die die horizontale Koordinate speichert (Spalten-Index im Raster).
};
