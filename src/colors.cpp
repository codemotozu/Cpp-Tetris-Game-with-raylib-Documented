/// Colors Implementation
/// 
/// Color definitions and utilities for the C++ Tetris game using raylib graphics library. // Farbdefinitionen und Hilfsfunktionen für das C++ Tetris-Spiel mit der raylib-Grafikbibliothek.
/// Defines RGBA color constants for all game elements including blocks, background, and UI. // Definiert RGBA-Farbkonstanten für alle Spielelemente einschließlich Blöcke, Hintergrund und UI.
/// 
/// Usage:
/// ```cpp
/// #include "colors.h"
/// 
/// std::vector<Color> gameColors = GetCellColors();
/// DrawRectangle(x, y, width, height, darkBlue);
/// ```
/// 
/// EN: Provides a comprehensive color palette for the Tetris game with classic colors for each piece type and UI elements.
/// DE: Bietet eine umfassende Farbpalette für das Tetris-Spiel mit klassischen Farben für jeden Blocktyp und UI-Elemente.

#include "colors.h" // Includes the colors header file with Color type definitions and function declarations. // Inkludiert die Farben-Header-Datei mit Color-Typ-Definitionen und Funktionsdeklarationen.

const Color darkGrey = {26, 31, 40, 255}; // Dark grey color for empty cells and backgrounds (RGBA: 26,31,40,255). // Dunkelgraue Farbe für leere Zellen und Hintergründe (RGBA: 26,31,40,255).
const Color green = {47, 230, 23, 255}; // Bright green color for S-shaped blocks (RGBA: 47,230,23,255). // Hellgrüne Farbe für S-förmige Blöcke (RGBA: 47,230,23,255).
const Color red = {232, 18, 18, 255}; // Bright red color for Z-shaped blocks (RGBA: 232,18,18,255). // Hellrote Farbe für Z-förmige Blöcke (RGBA: 232,18,18,255).
const Color orange = {226, 116, 17, 255}; // Orange color for L-shaped blocks (RGBA: 226,116,17,255). // Orange Farbe für L-förmige Blöcke (RGBA: 226,116,17,255).
const Color yellow = {237, 234, 4, 255}; // Bright yellow color for O-shaped (square) blocks (RGBA: 237,234,4,255). // Hellgelbe Farbe für O-förmige (quadratische) Blöcke (RGBA: 237,234,4,255).
const Color purple = {166, 0, 247, 255}; // Purple color for T-shaped blocks (RGBA: 166,0,247,255). // Lila Farbe für T-förmige Blöcke (RGBA: 166,0,247,255).
const Color cyan = {21, 204, 209, 255}; // Cyan color for I-shaped (line) blocks (RGBA: 21,204,209,255). // Cyan Farbe für I-förmige (Linien-) Blöcke (RGBA: 21,204,209,255).
const Color blue = {13, 64, 216, 255}; // Blue color for J-shaped blocks (RGBA: 13,64,216,255). // Blaue Farbe für J-förmige Blöcke (RGBA: 13,64,216,255).
const Color lightBlue = {59, 85, 162, 255}; // Light blue color for UI elements and score display (RGBA: 59,85,162,255). // Hellblaue Farbe für UI-Elemente und Punkteanzeige (RGBA: 59,85,162,255).
const Color darkBlue = {44, 44, 127, 255}; // Dark blue color for game background and borders (RGBA: 44,44,127,255). // Dunkelblaue Farbe für Spielhintergrund und Ränder (RGBA: 44,44,127,255).

std::vector<Color> GetCellColors() // Function that returns a vector containing colors for all block types in order. // Funktion, die einen Vektor mit Farben für alle Blocktypen in Reihenfolge zurückgibt.
{
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue}; // Returns color array indexed by block ID (0=empty, 1-7=block types). // Gibt Farb-Array zurück, indiziert nach Block-ID (0=leer, 1-7=Blocktypen).
    // Index 0: darkGrey for empty cells (ID 0). // Index 0: darkGrey für leere Zellen (ID 0).
    // Index 1: green for S-blocks (ID 1). // Index 1: grün für S-Blöcke (ID 1).
    // Index 2: red for Z-blocks (ID 2). // Index 2: rot für Z-Blöcke (ID 2).
    // Index 3: orange for L-blocks (ID 3). // Index 3: orange für L-Blöcke (ID 3).
    // Index 4: yellow for O-blocks (ID 4). // Index 4: gelb für O-Blöcke (ID 4).
    // Index 5: purple for T-blocks (ID 5). // Index 5: lila für T-Blöcke (ID 5).
    // Index 6: cyan for I-blocks (ID 6). // Index 6: cyan für I-Blöcke (ID 6).
    // Index 7: blue for J-blocks (ID 7). // Index 7: blau für J-Blöcke (ID 7).
}
