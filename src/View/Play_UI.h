/*Author :Linux_sky */
// typedef enum
// {
//     影片 = 1,
//     歌剧 = 2,
//     音乐会 = 3,
// }play_type_t;

// typedef enum{
//     儿童 = 1,
//     青少年 = 2,
//     成人 = 3
// }play_rating_t;

typedef struct 
{
    int year;
    int month;
    int day;
}ttms_data_t;

typedef struct 
{
    int  id; //剧目ID
    char name[31]; //剧目名称
    int type; //剧目类型 
    char area[9]; //出品地区
    int dating ; //适合年龄
    int duration ; //时长
    ttms_data_t start_data;
    ttms_data_t end_date;
    int price; //票价
}play_t;

typedef struct play_node
{
    play_t data;
    struct Play_node *prev;
    struct Play_node *next;

}play_node_t;

typedef play_node_t * play_list_t;

void Play_UI_MgtEntry();