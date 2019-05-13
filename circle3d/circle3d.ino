if (key == 'z')
    {
      if (c <= 5) {
        x = (sqrt(r*r - y * y));
        Serial.println(x);
        Serial.println(y);
        y -= 1;
        toggle_stop_x = 0;
        toggle_stop_y = 0;
        pos_x = true;
        pos_y = true;
      }
      else if (c <= 10)
      {
        x = (sqrt(r*r + y * y));
        moving_x -= x * 100;
        moving_y += y * 100;
        Serial.println(x);
        Serial.println(y);
        y -= 1;
        toggle_stop_x = 0;
        toggle_stop_y = 0;
        pos_x = true;
        pos_y = true;
      }
      c++;
    }
