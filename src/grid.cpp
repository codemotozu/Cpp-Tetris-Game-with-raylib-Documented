/// Grid Class Implementation
/// 
/// Core grid management implementation for the C++ Tetris game using raylib graphics library. // Kern-Raster-Verwaltungsimplementierung für das C++ Tetris-Spiel mit der raylib-Grafikbibliothek.
/// Manages the 20x10 Tetris playing field, including rendering, boundary checking, and line clearing mechanics. // Verwaltet das 20x10 Tetris-Spielfeld, einschließlich Rendering, Grenzprüfung und Linienräumungsmechanik.
/// 
/// Usage:
/// ```cpp
/// Grid gameGrid;
/// gameGrid.Initialize();  // Clear the grid
/// gameGrid.Draw();        // Render to screen
/// 
/// // Check cell state
/// if (gameGrid.IsCellEmpty(5, 3)) {
///     // Place block
/// }
/// 
/// // Clear completed lines
/// int linesCleared = gameGrid.ClearFullRows();
/// ```
/// 
/// EN: Implements the complete Tetris grid system with standard 20x10 dimensions and all necessary game mechanics.
/// DE: Implementiert das vollständige Tetris-Rastersystem mit Standard-20x10-Dimensionen und allen notwendigen Spielmechaniken.

#include "grid.h" // Includes the Grid class header file with method declarations and member variables. // Inkludiert die Grid-Klassen-Header-Datei mit Methodendeklarationen und Mitgliedsvariablen.
#include <iostream> // Includes input/output stream library for console debugging output. // Inkludiert Eingabe-/Ausgabe-Stream-Bibliothek für Konsolen-Debug-Ausgabe.
#include "colors.h" // Includes color definitions and utilities for grid cell rendering. // Inkludiert Farbdefinitionen und Hilfsfunktionen für Rasterzellen-Rendering.

Grid::Grid() // Constructor that initializes a new Grid instance with standard Tetris dimensions. // Konstruktor, der eine neue Grid-Instanz mit Standard-Tetris-Dimensionen initialisiert.
{
    numRows = 20; // Sets the grid height to 20 rows (standard Tetris playing field height). // Setzt die Rasterhöhe auf 20 Reihen (Standard-Tetris-Spielfeld-Höhe).
    numCols = 10; // Sets the grid width to 10 columns (standard Tetris playing field width). // Setzt die Rasterbreite auf 10 Spalten (Standard-Tetris-Spielfeld-Breite).
    cellSize = 30; // Sets each cell size to 30 pixels for rendering (30x30 pixel squares). // Setzt jede Zellgröße auf 30 Pixel für Rendering (30x30 Pixel-Quadrate).
    Initialize(); // Calls initialization method to clear all grid cells to empty state. // Ruft Initialisierungsmethode auf, um alle Rasterzellen auf leeren Zustand zu löschen.
    colors = GetCellColors(); // Retrieves color palette for rendering different block types and empty cells. // Ruft Farbpalette zum Rendern verschiedener Blocktypen und leerer Zellen ab.
}

void Grid::Initialize() // Clears the entire grid by setting all cells to empty state (value 0). // Löscht das gesamte Raster durch Setzen aller Zellen auf leeren Zustand (Wert 0).
{
    for (int row = 0; row < numRows; row++) // Iterates through each row from top (0) to bottom (19). // Iteriert durch jede Reihe von oben (0) bis unten (19).
    {
        for (int column = 0; column < numCols; column++) // Iterates through each column from left (0) to right (9). // Iteriert durch jede Spalte von links (0) bis rechts (9).
        {
            grid[row][column] = 0; // Sets cell to 0 (empty state, no block occupies this position). // Setzt Zelle auf 0 (leerer Zustand, kein Block belegt diese Position).
        }
    }
}

void Grid::Print() // Prints the grid state to console for debugging purposes (development tool). // Gibt den Rasterzustand zur Konsole für Debug-Zwecke aus (Entwicklungswerkzeug).
{
    for (int row = 0; row < numRows; row++) // Iterates through each row to print grid contents line by line. // Iteriert durch jede Reihe, um Rasterinhalt zeilenweise zu drucken.
    {
        for (int column = 0; column < numCols; column++) // Iterates through each column in the current row. // Iteriert durch jede Spalte in der aktuellen Reihe.
        {
            std::cout << grid[row][column] << " "; // Prints cell value followed by space (0=empty, 1-7=block types). // Druckt Zellwert gefolgt von Leerzeichen (0=leer, 1-7=Blocktypen).
        }
        std::cout << std::endl; // Prints newline after each row to format grid visually in console. // Druckt Neue-Zeile nach jeder Reihe, um Raster visuell in Konsole zu formatieren.
    }
}

void Grid::Draw() // Renders the entire grid to screen using raylib drawing functions. // Rendert das gesamte Raster auf den Bildschirm mit raylib-Zeichenfunktionen.
{
    for (int row = 0; row < numRows; row++) // Iterates through each row to draw all cells from top to bottom. // Iteriert durch jede Reihe, um alle Zellen von oben bis unten zu zeichnen.
    {
        for (int column = 0; column < numCols; column++) // Iterates through each column to draw all cells from left to right. // Iteriert durch jede Spalte, um alle Zellen von links bis rechts zu zeichnen.
        {
            int cellValue = grid[row][column]; // Gets the value stored in current cell (0=empty, 1-7=block ID). // Holt den in der aktuellen Zelle gespeicherten Wert (0=leer, 1-7=Block-ID).
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]); 
            // Draws rectangle using raylib function with calculated position and size. // Zeichnet Rechteck mit raylib-Funktion mit berechneter Position und Größe.
            // X position: column * 30 + 11 (grid offset), Y position: row * 30 + 11 (grid offset). // X-Position: Spalte * 30 + 11 (Raster-Offset), Y-Position: Reihe * 30 + 11 (Raster-Offset).
            // Width and height: 29 pixels (cellSize - 1 creates 1-pixel gap between cells). // Breite und Höhe: 29 Pixel (cellSize - 1 erzeugt 1-Pixel-Lücke zwischen Zellen).
            // Color: determined by cellValue using colors array (0=dark grey, 1-7=block colors). // Farbe: bestimmt durch cellValue mit colors-Array (0=dunkelgrau, 1-7=Blockfarben).
        }
    }
}

bool Grid::IsCellOutside(int row, int column) // Checks if given coordinates are outside valid grid boundaries. // Prüft, ob gegebene Koordinaten außerhalb gültiger Rastergrenzen sind.
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols) // Tests if coordinates are within valid range (0-19 for rows, 0-9 for columns). // Testet, ob Koordinaten im gültigen Bereich sind (0-19 für Reihen, 0-9 für Spalten).
    {
        return false; // Returns false if coordinates are inside valid grid boundaries. // Gibt falsch zurück, wenn Koordinaten innerhalb gültiger Rastergrenzen sind.
    }
    return true; // Returns true if coordinates are outside grid boundaries (invalid position). // Gibt wahr zurück, wenn Koordinaten außerhalb der Rastergrenzen sind (ungültige Position).
}

bool Grid::IsCellEmpty(int row, int column) // Checks if specified cell is empty and available for block placement. // Prüft, ob angegebene Zelle leer und für Blockplatzierung verfügbar ist.
{
    if (grid[row][column] == 0) // Tests if cell contains value 0 (empty state, no block present). // Testet, ob Zelle Wert 0 enthält (leerer Zustand, kein Block vorhanden).
    {
        return true; // Returns true if cell is empty and available for use. // Gibt wahr zurück, wenn Zelle leer und verfügbar für Verwendung ist.
    }
    return false; // Returns false if cell is occupied by a block (contains non-zero value). // Gibt falsch zurück, wenn Zelle von einem Block belegt ist (enthält Nicht-Null-Wert).
}

int Grid::ClearFullRows() // Main line-clearing algorithm that removes completed rows and handles gravity. // Haupt-Linienräumungsalgorithmus, der vollständige Reihen entfernt und Schwerkraft behandelt.
{
    int completed = 0; // Counter for tracking number of rows cleared in this operation. // Zähler zur Verfolgung der Anzahl geräumter Reihen in dieser Operation.
    for (int row = numRows - 1; row >= 0; row--) // Iterates from bottom row (19) to top row (0) for proper gravity handling. // Iteriert von unterster Reihe (19) zu oberster Reihe (0) für ordnungsgemäße Schwerkraftbehandlung.
    {
        if (IsRowFull(row)) // Checks if current row is completely filled with blocks. // Prüft, ob aktuelle Reihe vollständig mit Blöcken gefüllt ist.
        {
            ClearRow(row); // Removes all blocks from the completed row (sets all cells to 0). // Entfernt alle Blöcke aus der vollständigen Reihe (setzt alle Zellen auf 0).
            completed++; // Increments counter of cleared rows for scoring and sound effects. // Erhöht Zähler geräumter Reihen für Punktevergabe und Soundeffekte.
        }
        else if (completed > 0) // If rows below were cleared, move this row down to fill gaps. // Wenn Reihen darunter geräumt wurden, bewege diese Reihe nach unten, um Lücken zu füllen.
        {
            MoveRowDown(row, completed); // Moves current row down by number of cleared rows below it. // Bewegt aktuelle Reihe um Anzahl geräumter Reihen darunter nach unten.
        }
    }
    return completed; // Returns total number of rows cleared for scoring calculation. // Gibt Gesamtanzahl geräumter Reihen für Punkteberechnung zurück.
}

bool Grid::IsRowFull(int row) // Checks if specified row is completely filled with blocks (no empty cells). // Prüft, ob angegebene Reihe vollständig mit Blöcken gefüllt ist (keine leeren Zellen).
{
    for (int column = 0; column < numCols; column++) // Iterates through all columns in the specified row. // Iteriert durch alle Spalten in der angegebenen Reihe.
    {
        if (grid[row][column] == 0) // Checks if any cell in row is empty (value 0). // Prüft, ob irgendeine Zelle in der Reihe leer ist (Wert 0).
        {
            return false; // Returns false if any empty cell found (row is not complete). // Gibt falsch zurück, wenn irgendeine leere Zelle gefunden wird (Reihe ist nicht vollständig).
        }
    }
    return true; // Returns true if all cells in row contain blocks (row is complete). // Gibt wahr zurück, wenn alle Zellen in der Reihe Blöcke enthalten (Reihe ist vollständig).
}

void Grid::ClearRow(int row) // Clears all blocks from specified row by setting all cells to empty state. // Räumt alle Blöcke aus angegebener Reihe durch Setzen aller Zellen auf leeren Zustand.
{
    for (int column = 0; column < numCols; column++) // Iterates through all columns in the specified row. // Iteriert durch alle Spalten in der angegebenen Reihe.
    {
        grid[row][column] = 0; // Sets each cell to 0 (empty state, removing any block that was there). // Setzt jede Zelle auf 0 (leerer Zustand, entfernt jeden Block, der dort war).
    }
}

void Grid::MoveRowDown(int row, int numRows) // Moves specified row downward by given number of positions (gravity effect). // Bewegt angegebene Reihe um gegebene Anzahl Positionen nach unten (Schwerkrafteffekt).
{
    for (int column = 0; column < numCols; column++) // Iterates through all columns in the row to be moved. // Iteriert durch alle Spalten in der zu bewegenden Reihe.
    {
        grid[row + numRows][column] = grid[row][column]; // Copies cell content to new position below (row + numRows). // Kopiert Zellinhalt zur neuen Position darunter (Reihe + numRows).
        grid[row][column] = 0; // Clears original cell position after copying content down. // Löscht ursprüngliche Zellposition nach dem Kopieren des Inhalts nach unten.
    }
}
