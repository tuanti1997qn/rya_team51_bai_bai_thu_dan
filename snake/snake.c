/*
 * snake.c
 *
 *  Created on: Oct 6, 2017
 *      Author: tuanti1997qn
 */


#include "snake.h"

int8_t direction;    //  huong la so co 3 chu so va di chuyen nguoc thi huong am
uint8_t snake_length;
int16_t snake_body[snack_max_length], food , food_random_value;


//-----------------------------------------------------------------------------------------------------------------------
//* extern function
int8_t set_direct(int16_t dir)      // set huong cho con ran
{
    if(direction == -dir)           // kiem tra co bi nguoc huong khong
    {
        return fail;
    }
    direction = dir;
    return xem_fail;
}

void init_snake()
{
    snake_length = 3;
    snake_body[0] = 112;
    snake_body[1] = 113;
    snake_body[2] = 114;
    direction = 001;
    food = 777;
    set_led_cube(1, 1, 2);// set 3 Ä‘iá»ƒm thÃ¢n ráº¯n
    set_led_cube(1, 1, 3);
    set_led_cube(1, 1, 4);
    set_led_cube(7, 7, 7);// set Ä‘á»“ Äƒn
}

char creat_food(int16_t random_value)       // hÃ m nÃ y láº¥y giÃ¡ trá»‹ cá»§a giÃ¡ trá»‹ random. láº¥y giÃ¡ trá»‹ timer tá»« láº§n nháº¥n nÃºt gáº§n nháº¥t. trong trÆ°á»�ng há»£p fail láº¥y giÃ¡ trá»‹ timer sau fail
// hÃ m Ä‘Æ°á»£c gá»�i khi vá»«a Äƒn
{
    int8_t food_place[3];
    int16_t food_place_10;
    convert_8(random_value,food_place);     // láº¥y giÃ¡ trá»‹ random tá»« 1-8 cho Ä‘á»“ Äƒn
    food_place_10 = food_place[0]*100 + food_place[1]*10 +food_place[2];   // chuyá»ƒn thÃ nh 10
    convert_10(food_place_10, food_place);
    if( get_led_cube(food_place[0],food_place[1],food_place[2]) == 1)  // kiá»ƒm tra cÃ³ trÃ¹ng hay khÃ´ng
    {
        return fail;
    }
    food = food_place_10;          // khÃ´ng trÃ¹ng thÃ¬ gÃ¡n vÃ  set...
    set_led_cube(food_place[0],food_place[1],food_place[2]);
    return xem_fail;
}

void set_food_random_value(int16_t random_value)
{
    food_random_value = random_value;
}

//-----------------------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------------------
//* static function


void snake_move()               // ran di chuyen
{
    int length_body_snake = 0;
    int8_t descartes[3];
    convert_10(snake_body[length_body_snake] , descartes);      // duyet tu duoi den dau ran
    clear_led_cube(descartes[0] , descartes[1] , descartes[2]);     // xoa cai duoi duoi trong mang led cube
    for(length_body_snake = 0 ; length_body_snake < snake_length ; length_body_snake++ )        // dich chuyen len 1 don vi theo huong
    {
        snake_body[length_body_snake] = snake_body[length_body_snake + 1];
    }
    snake_body[length_body_snake] += direction;             // tang cai dau
    convert_10(snake_body[length_body_snake] , descartes);
    set_led_cube(descartes[0] , descartes[1] , descartes[2]);       // set dau ran vao mang quet led
}

void convert_10(int16_t num,int8_t *goal)                       // ham convert 1 so sang 3 chu cai cua he 10 vi huong cua con ran o dang so co 3 so
{
    *(goal+2) = num % 10;
    num /= 10;
    *(goal + 1) = num % 10;
    num /= 10;
    *goal = num % 10;
}

char check_snake_die()                                          // check xem ran chet chua , check sau khi goi move
{
    int8_t check_status[3];
    convert_10(snake_body[snake_length], check_status);         // lay cai dau con ran
    int i;
    for(i=0 ; i<3 ; i++)
    {
        if( check_status[i] >= over_max_wall )    // check dung tuong (chan tren)
        {
            return die;
        }
    }
    for(i = 0 ; i < snake_length ; i++)             // check ráº¯n cáº¯n thÃ¢n
    {
        if( snake_body[snake_length] == snake_body[i] )     // duyet het than ran
        {
            return die;
        }
    }
    return alive;
}

char check_snake_eat()      // check truoc khi move
{
    if((snake_body[snake_length] + direction) == food) // kiá»ƒm tra bÆ°á»›c tiáº¿p theo cÃ³ Äƒn Ä‘Æ°á»£c khÃ´ng?
    {
        return eat;
    }
    return no_eat;
}

void convert_8(int16_t num,int8_t *goal)            // hÃ m convert qua há»‡ bÃ¡t phÃ¢n láº¥y random Ä‘á»“ Äƒn cho ráº¯n
{
    *(goal + 2) = num % 7;
    num /= 7;
    *(goal + 1) = num %7 ;
    num /= 7;
    *goal = num % 7;
}

void snake_eat()        // ráº¯n Ä‘Ã£ Äƒn má»“i
{
    snake_length++;     // tÄƒng biáº¿n Ä‘á»™ dÃ i ráº¯n
    if(snake_length == snack_max_length)         // check Ä‘á»™ dÃ i ráº¯n báº±ng Ä‘á»™ dÃ i mÃ£ thÃ¬ win
    {
        snake_win();
    }
    snake_body[snake_length] = food;        // cÃ¡i Ä‘á»“ Äƒn thÃ nh Ä‘áº§u con ráº¯n
    int8_t descartes[3];
    convert_10(food, descartes);        // láº¥y 3 giÃ¡ trá»‹ x y z vÃ o trong máº£ng descartes
    set_led_cube(descartes[0], descartes[1], descartes[2]);
    while(!creat_food(food_random_value))                // Ä‘áº£o cá»§a cret_foot giÃ¡ trá»‹ hÃªt fail má»›i ngá»«ng lÃ m
    {
        food_random_value = get_random_value();
    }
}

int16_t get_random_value()          // láº¥y giÃ¡ trá»‹ "ngáº«u nhiÃªn" tá»« timer ra
{
    int16_t random_value;
                                    // á»Ÿ Ä‘Ã¢y lÃ  hÃ m láº¥y giÃ¡ trá»‹ cá»§a timer lÃºc Ä‘áº¿m khuyáº¿n cÃ¡o láº¥y timer nÃ o mÃ  khÃ´ng liÃªn quan Ä‘áº¿n con ráº¯n Ä‘á»ƒ trÃ¡nh máº¥t tÃ­nh random.
    return random_value;            // tráº£ vá»� giÃ¡ trá»‹ random
}

void snake_win()
{
                                // lÃ m cÃ¡i abc xyz gÃ¬ Ä‘áº¥y
                                // nghiÃªn cá»©u thá»­ reset báº±ng pháº§n má»�m. khÃ´ng thÃ¬ cho treo luÃ´n.
}
//-----------------------------------------------------------------------------------------------------------------------

