/// Main Application Entry Point
/// 
/// Main entry point and game loop implementation for the C++ Tetris game using raylib graphics library. // Haupteinstiegspunkt und Spielschleifenimplementierung für das C++ Tetris-Spiel mit der raylib-Grafikbibliothek.
/// Sets up the game window, manages the main game loop, and handles all UI rendering and timing. // Richtet das Spielfenster ein, verwaltet die Hauptspielschleife und behandelt alle UI-Rendering und Timing.
/// 
/// Usage:
/// ```cpp
/// // Compile and run the Tetris game
/// g++ -o tetris main.cpp game.cpp grid.cpp block.cpp colors.cpp position.cpp -lraylib
/// ./tetris
/// ```
/// 
/// EN: Implements the complete Tetris game application with window management, game loop, UI rendering, and event timing.
/// DE: Implementiert die vollständige Tetris-Spielanwendung mit Fensterverwaltung, Spielschleife, UI-Rendering und Event-Timing.

#include <raylib.h> // Includes raylib graphics library for window, input, audio, and drawing functions. // Inkludiert raylib-Grafikbibliothek für Fenster-, Eingabe-, Audio- und Zeichenfunktionen.
#include "game.h" // Includes the Game class header for main game logic and state management. // Inkludiert die Game-Klassen-Header für Hauptspiellogik und Zustandsverwaltung.
#include "colors.h" // Includes color definitions for background colors and UI elements. // Inkludiert Farbdefinitionen für Hintergrundfarben und UI-Elemente.
#include <iostream> // Includes input/output stream library for potential debugging output. // Inkludiert Eingabe-/Ausgabe-Stream-Bibliothek für potenzielle Debug-Ausgabe.

double lastUpdateTime = 0; // Global variable storing the timestamp of last automatic block movement. // Globale Variable, die den Zeitstempel der letzten automatischen Blockbewegung speichert.

bool EventTriggered(double interval) // Function that implements timing mechanism for automatic block falling. // Funktion, die Timing-Mechanismus für automatisches Blockfallen implementiert.
{
    double currentTime = GetTime(); // Gets current time in seconds since program start using raylib function. // Holt aktuelle Zeit in Sekunden seit Programmstart mit raylib-Funktion.
    if (currentTime - lastUpdateTime >= interval) // Checks if enough time has passed since last triggered event. // Prüft, ob genug Zeit seit dem letzten ausgelösten Event vergangen ist.
    {
        lastUpdateTime = currentTime; // Updates the last event time to current time for next interval calculation. // Aktualisiert die letzte Event-Zeit auf aktuelle Zeit für nächste Intervallberechnung.
        return true; // Returns true indicating that the timed event should be triggered now. // Gibt wahr zurück und zeigt an, dass das zeitgesteuerte Event jetzt ausgelöst werden soll.
    }
    return false; // Returns false if not enough time has passed for the next event. // Gibt falsch zurück, wenn nicht genug Zeit für das nächste Event vergangen ist.
}

int main() // Main function - the entry point of the Tetris application. // Main-Funktion - der Einstiegspunkt der Tetris-Anwendung.
{
    InitWindow(500, 620, "raylib Tetris"); // Creates game window with 500x620 pixel dimensions and title. // Erstellt Spielfenster mit 500x620 Pixel-Dimensionen und Titel.
    // Width: 500 pixels (grid + UI space), Height: 620 pixels (grid + score area). // Breite: 500 Pixel (Raster + UI-Platz), Höhe: 620 Pixel (Raster + Punktebereich).
    SetTargetFPS(60); // Sets target frame rate to 60 FPS for smooth gameplay and animations. // Setzt Ziel-Framerate auf 60 FPS für flüssiges Gameplay und Animationen.

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0); // Loads custom font from file with 64-pixel size for UI text. // Lädt benutzerdefinierte Schriftart aus Datei mit 64-Pixel-Größe für UI-Text.
    // Parameters: filename, font size, font chars (0=default), glyph count (0=default). // Parameter: Dateiname, Schriftgröße, Schriftzeichen (0=Standard), Glyphenanzahl (0=Standard).

    Game game = Game(); // Creates main Game object that manages all Tetris gameplay logic. // Erstellt Haupt-Game-Objekt, das alle Tetris-Spiellogik verwaltet.

    while (WindowShouldClose() == false) // Main game loop - continues until user closes window or presses ESC. // Hauptspielschleife - läuft weiter, bis Benutzer Fenster schließt oder ESC drückt.
    {
        UpdateMusicStream(game.music); // Updates background music stream to keep audio playing continuously. // Aktualisiert Hintergrundmusik-Stream, um Audio kontinuierlich zu spielen.
        game.HandleInput(); // Processes keyboard input for block movement, rotation, and game restart. // Verarbeitet Tastatureingaben für Blockbewegung, Rotation und Spielneustart.
        if (EventTriggered(0.2)) // Checks if 0.2 seconds (200ms) have passed for automatic block falling. // Prüft, ob 0,2 Sekunden (200ms) für automatisches Blockfallen vergangen sind.
        {
            game.MoveBlockDown(); // Automatically moves current block down one row (gravity effect). // Bewegt aktuellen Block automatisch eine Reihe nach unten (Schwerkrafteffekt).
        }

        BeginDrawing(); // Starts raylib drawing context for rendering frame content. // Startet raylib-Zeichenkontext zum Rendern von Frame-Inhalt.
        ClearBackground(darkBlue); // Clears screen with dark blue background color from colors.h. // Löscht Bildschirm mit dunkelblauer Hintergrundfarbe aus colors.h.
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE); // Draws "Score" label at top-right position with white color. // Zeichnet "Score"-Beschriftung an oberer rechter Position mit weißer Farbe.
        // Parameters: font, text, position {x,y}, font size, spacing, color. // Parameter: Schriftart, Text, Position {x,y}, Schriftgröße, Abstand, Farbe.
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE); // Draws "Next" label above next block preview area. // Zeichnet "Next"-Beschriftung über nächstem Block-Vorschaubereich.
        if (game.gameOver) // Checks if game is in game-over state to display end message. // Prüft, ob Spiel im Game-Over-Zustand ist, um Endnachricht anzuzeigen.
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE); // Displays "GAME OVER" message when game ends. // Zeigt "GAME OVER"-Nachricht an, wenn Spiel endet.
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue); // Draws rounded rectangle background for score display area. // Zeichnet abgerundetes Rechteck als Hintergrund für Punkteanzeigebereich.
        // Parameters: rectangle {x, y, width, height}, roundness, segments, color. // Parameter: Rechteck {x, y, Breite, Höhe}, Rundung, Segmente, Farbe.

        char scoreText[10]; // Character array to hold score text (up to 9 digits + null terminator). // Zeichen-Array zum Halten des Punktetexts (bis zu 9 Ziffern + Null-Terminator).
        sprintf(scoreText, "%d", game.score); // Converts integer score to string format for display. // Konvertiert Ganzzahl-Punktzahl zu String-Format für Anzeige.
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); // Measures text dimensions for centering calculation. // Misst Textdimensionen für Zentrierung-Berechnung.

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE); // Draws centered score text inside score rectangle. // Zeichnet zentrierten Punktetext innerhalb des Punkte-Rechtecks.
        // X position: rectangle start + (rectangle width - text width) / 2 for centering. // X-Position: Rechteck-Start + (Rechteck-Breite - Text-Breite) / 2 für Zentrierung.
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue); // Draws rounded rectangle background for next block preview area. // Zeichnet abgerundetes Rechteck als Hintergrund für nächsten Block-Vorschaubereich.
        game.Draw(); // Calls game's Draw method to render grid, current block, and next block preview. // Ruft Draw-Methode des Spiels auf, um Raster, aktuellen Block und nächste Blockvorschau zu rendern.
        EndDrawing(); // Ends raylib drawing context and presents the completed frame to screen. // Beendet raylib-Zeichenkontext und präsentiert den vollständigen Frame auf dem Bildschirm.
    }

    CloseWindow(); // Closes the game window and cleans up raylib resources before program exit. // Schließt das Spielfenster und bereinigt raylib-Ressourcen vor Programmende.
}
