/// Grid Class Header
/// 
/// Header file declaring the Grid class interface for the C++ Tetris game using raylib graphics library. // Header-Datei, die die Grid-Klassen-Schnittstelle für das C++ Tetris-Spiel mit der raylib-Grafikbibliothek deklariert.
/// Defines the 20x10 Tetris playing field with all methods for grid management, rendering, and line clearing. // Definiert das 20x10 Tetris-Spielfeld mit allen Methoden für Rasterverwaltung, Rendering und Linienräumung.
/// 
/// Usage:
/// ```cpp
/// #include "grid.h"
/// 
/// Grid gameGrid;
/// gameGrid.Initialize();          // Clear the grid
/// gameGrid.Draw();               // Render to screen
/// 
/// // Check cell states
/// if (!gameGrid.IsCellEmpty(5, 3)) {
///     // Cell is occupied by a block
/// }
/// 
/// // Clear completed lines
/// int cleared = gameGrid.ClearFullRows();
/// if (cleared > 0) {
///     // Lines were cleared, update score
/// }
/// ```
/// 
/// EN: Declares the complete Tetris grid interface with standard 20x10 dimensions and all necessary game mechanics.
/// DE: Deklariert die vollständige Tetris-Raster-Schnittstelle mit Standard-20x10-Dimensionen und allen notwendigen Spielmechaniken.

#pragma once // Ensures this header file is included only once during compilation to prevent duplicate definitions. // Stellt sicher, dass diese Header-Datei nur einmal während der Kompilierung eingebunden wird, um doppelte Definitionen zu verhindern.
#include <vector> // Includes standard vector container for dynamic color array storage. // Inkludiert Standard-Vektor-Container für dynamische Farb-Array-Speicherung.
#include <raylib.h> // Includes raylib graphics library for Color type and drawing functions. // Inkludiert raylib-Grafikbibliothek für Color-Typ und Zeichenfunktionen.

class Grid // Declares the Grid class that represents the Tetris playing field and manages all grid operations. // Deklariert die Grid-Klasse, die das Tetris-Spielfeld repräsentiert und alle Raster-Operationen verwaltet.
{
public: // Public interface accessible from outside the class for external grid operations. // Öffentliche Schnittstelle, die von außerhalb der Klasse für externe Raster-Operationen zugänglich ist.
    Grid(); // Constructor declaration that initializes a new Grid instance with standard Tetris dimensions. // Konstruktor-Deklaration, die eine neue Grid-Instanz mit Standard-Tetris-Dimensionen initialisiert.
    void Initialize(); // Method declaration for clearing all grid cells to empty state (value 0). // Methoden-Deklaration zum Löschen aller Rasterzellen auf leeren Zustand (Wert 0).
    void Print(); // Method declaration for printing grid state to console for debugging purposes. // Methoden-Deklaration zum Drucken des Rasterzustands zur Konsole für Debug-Zwecke.
    void Draw(); // Method declaration for rendering the entire grid to screen using raylib drawing functions. // Methoden-Deklaration zum Rendern des gesamten Rasters auf den Bildschirm mit raylib-Zeichenfunktionen.
    bool IsCellOutside(int row, int column); // Method declaration that checks if given coordinates are outside valid grid boundaries. // Methoden-Deklaration, die prüft, ob gegebene Koordinaten außerhalb gültiger Rastergrenzen sind.
    bool IsCellEmpty(int row, int column); // Method declaration that checks if specified cell is empty and available for block placement. // Methoden-Deklaration, die prüft, ob angegebene Zelle leer und für Blockplatzierung verfügbar ist.
    int ClearFullRows(); // Method declaration for the main line-clearing algorithm that returns number of rows cleared. // Methoden-Deklaration für den Haupt-Linienräumungsalgorithmus, der die Anzahl geräumter Reihen zurückgibt.
    int grid[20][10]; // Public 2D array representing the 20x10 Tetris playing field (20 rows, 10 columns). // Öffentliches 2D-Array, das das 20x10 Tetris-Spielfeld repräsentiert (20 Reihen, 10 Spalten).
    // Array values: 0 = empty cell, 1-7 = different Tetris block types. // Array-Werte: 0 = leere Zelle, 1-7 = verschiedene Tetris-Blocktypen.

private: // Private members accessible only within the Grid class for internal grid management. // Private Mitglieder, die nur innerhalb der Grid-Klasse für interne Rasterverwaltung zugänglich sind.
    bool IsRowFull(int row); // Private method declaration that checks if specified row is completely filled with blocks. // Private Methoden-Deklaration, die prüft, ob angegebene Reihe vollständig mit Blöcken gefüllt ist.
    void ClearRow(int row); // Private method declaration for clearing all blocks from specified row (sets all cells to 0). // Private Methoden-Deklaration zum Löschen aller Blöcke aus angegebener Reihe (setzt alle Zellen auf 0).
    void MoveRowDown(int row, int numRows); // Private method declaration for moving specified row downward by given number of positions. // Private Methoden-Deklaration zum Bewegen angegebener Reihe um gegebene Anzahl Positionen nach unten.
    int numRows; // Private integer storing the number of rows in the grid (standard value: 20). // Private Ganzzahl, die die Anzahl der Reihen im Raster speichert (Standardwert: 20).
    int numCols; // Private integer storing the number of columns in the grid (standard value: 10). // Private Ganzzahl, die die Anzahl der Spalten im Raster speichert (Standardwert: 10).
    int cellSize; // Private integer storing the pixel size of each cell for rendering (standard value: 30). // Private Ganzzahl, die die Pixelgröße jeder Zelle für Rendering speichert (Standardwert: 30).
    std::vector<Color> colors; // Private vector containing color palette for rendering different block types and empty cells. // Privater Vektor mit Farbpalette zum Rendern verschiedener Blocktypen und leerer Zellen.
};
