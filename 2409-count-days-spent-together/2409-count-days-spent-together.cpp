class Solution {
public:
    int getDay(string date) {

            int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            int total = day;

            for (int i = 0; i < month - 1; i++) {
                total += days[i];
            }

            return total;
        }
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {


        int aStart = getDay(arriveAlice);
        int aLeave = getDay(leaveAlice);
        int bStart = getDay(arriveBob);
        int bLeave = getDay(leaveBob);

        int start = max(aStart, bStart);
        int leave = min(aLeave, bLeave);

        if(start > leave){
            return 0;
        }
        else{
            return leave - start +1;
        }
    }
};