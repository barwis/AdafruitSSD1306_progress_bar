
/** 
 * Simple progress bar for 128x32 and 128x64 OLED displays (but will work with others as well!)
*/

#include <Adafruit_SSD1306.h>

void progressBar (
    Adafruit_SSD1306 display, 
    int value
) {    // if you're using different display/driver, change type accordingly

    // total width: 126px
    // 1px left/right margin
    const int x1 = 1;
    const int x2 = SCREEN_WIDTH - 2;

    // total height 13px
    const int y1 = 18;
    const int y2 = SCREEN_HEIGHT - 2;

    // reset and display settings
    // if you're using different drivers,
    // please refer to driver documentation

    display.clearDisplay();
    display.setTextSize(1);               // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);  // Draw white text
    display.setCursor(0, 0);    

    // top border
    display.drawLine(x1 + 1, y1, x2 - 1, y1, SSD1306_WHITE);

    // bottom border
    display.drawLine(x1 + 1, y2, x2 - 1, y2, SSD1306_WHITE);

    // left border
    display.drawLine(x1, y1 + 1, x1, y2 - 1, SSD1306_WHITE);

    // right border
    display.drawLine(x2, y1 + 1, x2, y2 - 1, SSD1306_WHITE);

    // calculate width and draw progress bar
    const int width = (round(x2 - x1 - 2) * dimmerValue / 100);
    display.fillRect(x1 + 2, y1 + 2, width, (y2 - y1 - 3), SSD1306_WHITE);

    // calculate horizontal center text position
    int textWidth = dimmerValue < 10 ? 6 : 9;
    
    display.setTextColor(SSD1306_INVERSE);
    display.setCursor((64 - textWidth), 21); // adjust Y parameter if needed. dependant on text size and progress bar Y position

    display.print(value);
    display.print(F("%"));

    display.display(); 
}