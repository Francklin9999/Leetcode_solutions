class Robot {
int w;
int h;
int x{};
int y{};
int direction;
int perimeter;
public:
    Robot(int width, int height) : w(width), h(height), direction(0) {
        perimeter = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        num %= perimeter;
        if (num == 0) {num = perimeter;}
        switch (direction) {
            case 0:
                {
                    auto n = w - 1 - x;
                    if (num <= n) {
                        x = x + num;
                    } else {
                        x = w - 1;
                        direction = 1;
                        step(num - n);
                    } 
                    return;
                }
            case 1:    
                {      
                    auto n = h - 1 - y;
                    if (num <= n) {
                        y = y + num;
                    } else {
                        y = h - 1;
                        direction = 2;
                        step(num - n);
                    } 
                    return;
                }
            case 2:
               {      
                    auto n = x;
                    if (num <= n) {
                        x = x - num;
                    } else {
                        x = 0;
                        direction = 3;
                        step(num - n);
                    } 
                    return;
                }
            case 3:       
                    auto n = y;
                    if (num <= n) {
                        y = y - num;
                    } else {
                        y = 0;
                        direction = 0;
                        step(num - n);
                    } 
                    return;       
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        switch (direction) {
            case 0:
                return "East";
            case 1:
                return "North";
            case 2:
                return "West";
            case 3:
                return "South";
            default:
                return "Cooked";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */