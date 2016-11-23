#include "intset.h"


int main(int argc, char const *argv[]) {

        intset tmpset1;

        addtointset(&tmpset1, 4);

        addtointset(&tmpset1, 4);
        addtointset(&tmpset1, 1);

        addtointset(&tmpset1, 5);
        addtointset(&tmpset1, 6);
        addtointset(&tmpset1, 8);
        addtointset(&tmpset1, 23);
        addtointset(&tmpset1, 11);
        printintset(tmpset1);

        intset tmpset2;

        addtointset(&tmpset2, 3);

        addtointset(&tmpset2, 12);

        addtointset(&tmpset2, 8);
        addtointset(&tmpset2, 5);
        addtointset(&tmpset2, 24);
        addtointset(&tmpset2, 11);
        addtointset(&tmpset2, 1);
        printintset(tmpset2);

        // rmfrmintset(&tmpset1, 4);
        // rmelmintset(&tmpset1, 4);
        // printintset(tmpset1);

        printintset(unionintsets(tmpset1, tmpset2));
        printintset(intplusset(10,tmpset1));
        printintset(intmultset(10,tmpset1));
        printintset(setplusset(tmpset2,tmpset1));
        printintset(setmultset(tmpset2,tmpset1));
        printintset(diffintset(tmpset1, tmpset2));
        printintset(extintset(tmpset1, tmpset2));
        printintset(intintset(tmpset1, tmpset2));
        //insertintset(&tmpset1,41, 3);
        //printintset(tmpset1);
        printf("%d\n", sumintset(tmpset1));

        intlist tmplist1;

        return 0;
}
