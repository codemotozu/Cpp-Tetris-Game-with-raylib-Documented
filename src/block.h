/// Block Class Header
/// 
/// Header file defining the Block class for the C++ Tetris game using raylib. // Header-Datei, die die Block-Klasse für das C++ Tetris-Spiel mit raylib definiert.
/// Declares the interface for Tetris block objects with rendering, movement, and rotation capabilities. // Deklariert die Schnittstelle für Tetris-Block-Objekte mit Rendering-, Bewegungs- und Rotationsfähigkeiten.
/// 
/// Usage:
/// ```cpp
/// #include "block.h"
/// 
/// Block tetrisBlock;
/// tetrisBlock.Draw(100, 100);
/// tetrisBlock.Move(1, 0);
/// tetrisBlock.Rotate();
/// ```
/// 
/// EN: Provides the class interface for all Tetris blocks, including geometric data, rendering methods, and movement operations.
/// DE: Bietet die Klassenschnittstelle für alle Tetris-Blöcke, einschließlich geometrischer Daten, Rendering-Methoden und Bewegungsoperationen.

#pragma once // Ensures this header file is included only once during compilation. // Stellt sicher, dass diese Header-Datei nur einmal während der Kompilierung eingebunden wird.
#include <vector> // Includes the standard vector container for dynamic arrays. // Inkludiert den Standard-Vektor-Container für dynamische Arrays.
#include <map> // Includes the standard map container for key-value pairs. // Inkludiert den Standard-Map-Container für Schlüssel-Wert-Paare.
#include "position.h" // Includes the Position class for handling row/column coordinates. // Inkludiert die Position-Klasse für die Behandlung von Zeilen-/Spalten-Koordinaten.
#include "colors.h" // Includes color definitions and utilities for block rendering. // Inkludiert Farbdefinitionen und Hilfsfunktionen für Block-Rendering.

class Block // Defines the Block class that represents a Tetris game piece. // Definiert die Block-Klasse, die ein Tetris-Spielstück repräsentiert.
{
public: // Public interface accessible from outside the class. // Öffentliche Schnittstelle, die von außerhalb der Klasse zugänglich ist.
    Block(); // Default constructor that initializes a new Block instance. // Standard-Konstruktor, der eine neue Block-Instanz initialisiert.
    void Draw(int offsetX, int offsetY); // Renders the block on screen at specified offset coordinates. // Rendert den Block auf dem Bildschirm an den angegebenen Offset-Koordinaten.
    void Move(int rows, int columns); // Moves the block by specified number of rows and columns. // Bewegt den Block um die angegebene Anzahl von Zeilen und Spalten.
    std::vector<Position> GetCellPositions(); // Returns current positions of all cells that make up the block. // Gibt aktuelle Positionen aller Zellen zurück, die den Block bilden.
    void Rotate(); // Rotates the block to its next rotation state (clockwise). // Rotiert den Block zum nächsten Rotationszustand (im Uhrzeigersinn).
    void UndoRotation(); // Reverses the last rotation operation (for collision handling). // Macht die letzte Rotationsoperation rückgängig (für Kollisionsbehandlung).
    int id; // Unique identifier for the block type (1-7 for different Tetris pieces). // Eindeutige Kennung für den Blocktyp (1-7 für verschiedene Tetris-Stücke).
    std::map<int, std::vector<Position>> cells; // Maps rotation states to their corresponding cell positions. // Ordnet Rotationszustände ihren entsprechenden Zellpositionen zu.
    // Key: rotation state (0-3), Value: vector of Position objects defining the shape. // Schlüssel: Rotationszustand (0-3), Wert: Vektor von Position-Objekten, die die Form definieren.

private: // Private members accessible only within the class. // Private Mitglieder, die nur innerhalb der Klasse zugänglich sind.
    int cellSize; // Size of each cell in pixels (typically 30x30). // Größe jeder Zelle in Pixeln (typischerweise 30x30).
    int rotationState; // Current rotation state index (0-3 for most blocks). // Aktueller Rotationszustand-Index (0-3 für die meisten Blöcke).
    std::vector<Color> colors; // Color palette used for rendering different block types. // Farbpalette, die zum Rendern verschiedener Blocktypen verwendet wird.
    int rowOffset; // Vertical position offset from the original position. // Vertikaler Positions-Offset von der ursprünglichen Position.
    int columnOffset; // Horizontal position offset from the original position. // Horizontaler Positions-Offset von der ursprünglichen Position.
};
