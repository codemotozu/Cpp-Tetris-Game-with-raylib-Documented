/// Tetris Block Classes Implementation
/// 
/// Defines all seven classic Tetris block types (Tetrominoes) for the C++ Tetris game. // Definiert alle sieben klassischen Tetris-Blocktypen (Tetrominoes) für das C++ Tetris-Spiel.
/// Each block class inherits from the base Block class and defines its unique shape and rotation states. // Jede Block-Klasse erbt von der Basis-Block-Klasse und definiert ihre einzigartige Form und Rotationszustände.
/// 
/// Usage:
/// ```cpp
/// LBlock lBlock;  // Creates an L-shaped piece
/// JBlock jBlock;  // Creates a reverse L-shaped piece
/// IBlock iBlock;  // Creates a straight line piece
/// // ... and so on for all 7 Tetris pieces
/// ```
/// 
/// EN: Implements the seven standard Tetris pieces with their geometric definitions and starting positions.
/// DE: Implementiert die sieben Standard-Tetris-Stücke mit ihren geometrischen Definitionen und Startpositionen.

#include "block.h" // Includes the base Block class definition for inheritance. // Inkludiert die Basis-Block-Klassendefinition für Vererbung.
#include "position.h" // Includes the Position class for defining cell coordinates. // Inkludiert die Position-Klasse für die Definition von Zellkoordinaten.

class LBlock : public Block // L-shaped Tetris piece (orange in classic Tetris). // L-förmiges Tetris-Stück (orange im klassischen Tetris).
{
public: // Public interface accessible from outside the class. // Öffentliche Schnittstelle, die von außerhalb der Klasse zugänglich ist.
    LBlock() // Constructor that initializes the L-block with all rotation states. // Konstruktor, der den L-Block mit allen Rotationszuständen initialisiert.
    {
        id = 1; // Sets unique identifier for L-block type. // Setzt eindeutige Kennung für L-Block-Typ.
        cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)}; // Rotation state 0: L-shape facing right. // Rotationszustand 0: L-Form nach rechts gerichtet.
        cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)}; // Rotation state 1: L-shape facing down. // Rotationszustand 1: L-Form nach unten gerichtet.
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)}; // Rotation state 2: L-shape facing left. // Rotationszustand 2: L-Form nach links gerichtet.
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)}; // Rotation state 3: L-shape facing up. // Rotationszustand 3: L-Form nach oben gerichtet.
        Move(0, 3); // Positions the block at column 3 (center of game grid). // Positioniert den Block in Spalte 3 (Mitte des Spielfelds).
    }
};

class JBlock : public Block // Reverse L-shaped Tetris piece (blue in classic Tetris). // Umgekehrt L-förmiges Tetris-Stück (blau im klassischen Tetris).
{
public: // Public interface accessible from outside the class. // Öffentliche Schnittstelle, die von außerhalb der Klasse zugänglich ist.
    JBlock() // Constructor that initializes the J-block with all rotation states. // Konstruktor, der den J-Block mit allen Rotationszuständen initialisiert.
    {
        id = 2; // Sets unique identifier for J-block type. // Setzt eindeutige Kennung für J-Block-Typ.
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)}; // Rotation state 0: J-shape facing right. // Rotationszustand 0: J-Form nach rechts gerichtet.
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)}; // Rotation state 1: J-shape facing down. // Rotationszustand 1: J-Form nach unten gerichtet.
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)}; // Rotation state 2: J-shape facing left. // Rotationszustand 2: J-Form nach links gerichtet.
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)}; // Rotation state 3: J-shape facing up. // Rotationszustand 3: J-Form nach oben gerichtet.
        Move(0, 3); // Positions the block at column 3 (center of game grid). // Positioniert den Block in Spalte 3 (Mitte des Spielfelds).
    }
};

class IBlock : public Block // Straight line Tetris piece (cyan in classic Tetris). // Gerade Linie Tetris-Stück (cyan im klassischen Tetris).
{
public: // Public interface accessible from outside the class. // Öffentliche Schnittstelle, die von außerhalb der Klasse zugänglich ist.
    IBlock() // Constructor that initializes the I-block with horizontal and vertical orientations. // Konstruktor, der den I-Block mit horizontalen und vertikalen Ausrichtungen initialisiert.
    {
        id = 3; // Sets unique identifier for I-block type. // Setzt eindeutige Kennung für I-Block-Typ.
        cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)}; // Rotation state 0: horizontal line. // Rotationszustand 0: horizontale Linie.
        cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)}; // Rotation state 1: vertical line. // Rotationszustand 1: vertikale Linie.
        cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)}; // Rotation state 2: horizontal line (shifted). // Rotationszustand 2: horizontale Linie (verschoben).
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)}; // Rotation state 3: vertical line (shifted). // Rotationszustand 3: vertikale Linie (verschoben).
        Move(-1, 3); // Positions the block slightly higher (-1 row) at column 3. // Positioniert den Block etwas höher (-1 Zeile) in Spalte 3.
    }
};

class OBlock : public Block // Square-shaped Tetris piece (yellow in classic Tetris). // Quadratförmiges Tetris-Stück (gelb im klassischen Tetris).
{
public: // Public interface accessible from outside the class. // Öffentliche Schnittstelle, die von außerhalb der Klasse zugänglich ist.
    OBlock() // Constructor that initializes the O-block (square doesn't rotate). // Konstruktor, der den O-Block initialisiert (Quadrat rotiert nicht).
    {
        id = 4; // Sets unique identifier for O-block type. // Setzt eindeutige Kennung für O-Block-Typ.
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)}; // Only rotation state: 2x2 square shape. // Einziger Rotationszustand: 2x2 Quadratform.
        // Note: O-block only has one rotation state since it's symmetrical. // Hinweis: O-Block hat nur einen Rotationszustand, da er symmetrisch ist.
        Move(0, 4); // Positions the block at column 4 (slightly right of center). // Positioniert den Block in Spalte 4 (etwas rechts der Mitte).
    }
};

class SBlock : public Block // S-shaped Tetris piece (green in classic Tetris). // S-förmiges Tetris-Stück (grün im klassischen Tetris).
{
public: // Public interface accessible from outside the class. // Öffentliche Schnittstelle, die von außerhalb der Klasse zugänglich ist.
    SBlock() // Constructor that initializes the S-block with all rotation states. // Konstruktor, der den S-Block mit allen Rotationszuständen initialisiert.
    {
        id = 5; // Sets unique identifier for S-block type. // Setzt eindeutige Kennung für S-Block-Typ.
        cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)}; // Rotation state 0: S-shape horizontal. // Rotationszustand 0: S-Form horizontal.
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)}; // Rotation state 1: S-shape vertical. // Rotationszustand 1: S-Form vertikal.
        cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)}; // Rotation state 2: S-shape horizontal (flipped). // Rotationszustand 2: S-Form horizontal (gespiegelt).
        cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)}; // Rotation state 3: S-shape vertical (flipped). // Rotationszustand 3: S-Form vertikal (gespiegelt).
        Move(0, 3); // Positions the block at column 3 (center of game grid). // Positioniert den Block in Spalte 3 (Mitte des Spielfelds).
    }
};

class TBlock : public Block // T-shaped Tetris piece (purple in classic Tetris). // T-förmiges Tetris-Stück (lila im klassischen Tetris).
{
public: // Public interface accessible from outside the class. // Öffentliche Schnittstelle, die von außerhalb der Klasse zugänglich ist.
    TBlock() // Constructor that initializes the T-block with all rotation states. // Konstruktor, der den T-Block mit allen Rotationszuständen initialisiert.
    {
        id = 6; // Sets unique identifier for T-block type. // Setzt eindeutige Kennung für T-Block-Typ.
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)}; // Rotation state 0: T-shape facing up. // Rotationszustand 0: T-Form nach oben gerichtet.
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)}; // Rotation state 1: T-shape facing right. // Rotationszustand 1: T-Form nach rechts gerichtet.
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)}; // Rotation state 2: T-shape facing down. // Rotationszustand 2: T-Form nach unten gerichtet.
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)}; // Rotation state 3: T-shape facing left. // Rotationszustand 3: T-Form nach links gerichtet.
        Move(0, 3); // Positions the block at column 3 (center of game grid). // Positioniert den Block in Spalte 3 (Mitte des Spielfelds).
    }
};

class ZBlock : public Block // Z-shaped Tetris piece (red in classic Tetris). // Z-förmiges Tetris-Stück (rot im klassischen Tetris).
{
public: // Public interface accessible from outside the class. // Öffentliche Schnittstelle, die von außerhalb der Klasse zugänglich ist.
    ZBlock() // Constructor that initializes the Z-block with all rotation states. // Konstruktor, der den Z-Block mit allen Rotationszuständen initialisiert.
    {
        id = 7; // Sets unique identifier for Z-block type. // Setzt eindeutige Kennung für Z-Block-Typ.
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)}; // Rotation state 0: Z-shape horizontal. // Rotationszustand 0: Z-Form horizontal.
        cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)}; // Rotation state 1: Z-shape vertical. // Rotationszustand 1: Z-Form vertikal.
        cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)}; // Rotation state 2: Z-shape horizontal (flipped). // Rotationszustand 2: Z-Form horizontal (gespiegelt).
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)}; // Rotation state 3: Z-shape vertical (flipped). // Rotationszustand 3: Z-Form vertikal (gespiegelt).
        Move(0, 3); // Positions the block at column 3 (center of game grid). // Positioniert den Block in Spalte 3 (Mitte des Spielfelds).
    }
};
