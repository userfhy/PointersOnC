/**
 * 表示长途电话付账记录的结构
 */
enum PN_TYPE{CALLED, CALLING, BILLED};

struct LONG_DISTANCE_BILL {
    short month;
    short day;
    short year;
    int time;
    struct PHONE_NUMBER numbers[3];
}
