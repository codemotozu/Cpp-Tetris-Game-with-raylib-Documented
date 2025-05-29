/// Colors Header
/// 
/// Header file declaring color constants and utilities for the C++ Tetris game using raylib. // Header-Datei, die Farbkonstanten und Hilfsfunktionen für das C++ Tetris-Spiel mit raylib deklariert.
/// Provides external declarations for all game colors and color management functions. // Bietet externe Deklarationen für alle Spielfarben und Farbverwaltungsfunktionen.
/// 
/// Usage:
/// ```cpp
/// #include "colors.h"
/// 
/// // Use predefined colors
/// DrawRectangle(x, y, w, h, darkBlue);
/// 
/// // Get color array for blocks
/// std::vector<Color> colors = GetCellColors();
/// DrawRectangle(x, y, w, h, colors[blockId]);
/// ```
/// 
/// EN: Declares the color palette interface for the Tetris game, including block colors and UI element colors.
/// DE: Deklariert die Farbpaletten-Schnittstelle für das Tetris-Spiel, einschließlich Block-Farben und UI-Element-Farben.

#pragma once // Ensures this header file is included only once during compilation. // Stellt sicher, dass diese Header-Datei nur einmal während der Kompilierung eingebunden wird.
#include <raylib.h> // Includes raylib graphics library for Color type definition. // Inkludiert die raylib-Grafikbibliothek für die Color-Typ-Definition.
#include <vector> // Includes standard vector container for dynamic color arrays. // Inkludiert den Standard-Vektor-Container für dynamische Farb-Arrays.

extern const Color darkGrey; // External declaration for dark grey color used in empty cells and backgrounds. // Externe Deklaration für dunkelgraue Farbe, die in leeren Zellen und Hintergründen verwendet wird.
extern const Color green; // External declaration for bright green color used in S-shaped Tetris blocks. // Externe Deklaration für hellgrüne Farbe, die in S-förmigen Tetris-Blöcken verwendet wird.
extern const Color red; // External declaration for bright red color used in Z-shaped Tetris blocks. // Externe Deklaration für hellrote Farbe, die in Z-förmigen Tetris-Blöcken verwendet wird.
extern const Color orange; // External declaration for orange color used in L-shaped Tetris blocks. // Externe Deklaration für orange Farbe, die in L-förmigen Tetris-Blöcken verwendet wird.
extern const Color yellow; // External declaration for bright yellow color used in O-shaped (square) Tetris blocks. // Externe Deklaration für hellgelbe Farbe, die in O-förmigen (quadratischen) Tetris-Blöcken verwendet wird.
extern const Color purple; // External declaration for purple color used in T-shaped Tetris blocks. // Externe Deklaration für lila Farbe, die in T-förmigen Tetris-Blöcken verwendet wird.
extern const Color cyan; // External declaration for cyan color used in I-shaped (line) Tetris blocks. // Externe Deklaration für cyan Farbe, die in I-förmigen (Linien-) Tetris-Blöcken verwendet wird.
extern const Color blue; // External declaration for blue color used in J-shaped Tetris blocks. // Externe Deklaration für blaue Farbe, die in J-förmigen Tetris-Blöcken verwendet wird.
extern const Color lightBlue; // External declaration for light blue color used in UI elements and score display. // Externe Deklaration für hellblaue Farbe, die in UI-Elementen und Punkteanzeige verwendet wird.
extern const Color darkBlue; // External declaration for dark blue color used in game background and borders. // Externe Deklaration für dunkelblaue Farbe, die in Spielhintergrund und Rändern verwendet wird.

std::vector<Color> GetCellColors(); // Function declaration that returns a vector of colors indexed by block ID (0-7). // Funktionsdeklaration, die einen Vektor von Farben zurückgibt, indiziert nach Block-ID (0-7).
// Returns: Vector with colors for empty cells (index 0) and all seven Tetris block types (indices 1-7). // Rückgabe: Vektor mit Farben für leere Zellen (Index 0) und alle sieben Tetris-Blocktypen (Indizes 1-7).
