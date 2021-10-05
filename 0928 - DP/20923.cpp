#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//그라운드에 있는 카드를 덱으로 옮기는 함수
void moveCard(deque<int> &deck, deque<int> &ground) {
    //그라운드가 empty가 아닐때까지 반복한다.
    while (!ground.empty()) {
        //deck 으로 옮기고
        deck.push_back(ground.back());
        ground.pop_back(); //그라운드꺼 제거
    }
}

//게임을 진행하는 함수
pair<int, int> playGame(int m, vector<deque<int>> &deck, vector<deque<int>> &ground) {
    bool turn = false; //도도부터 시작

    while (m--) {
        //이번 턴의 사람이 카드 뒤집어서 그라운드에 올려놓기
        int card = deck[turn].front(); //맨앞 께 card로 저장
        ground[turn].push_front(card); //그라운드에 올려놓고
        deck[turn].pop_front();//이번턴의 사람꺼 deck에서 pop해서 제거

        //게임 진행 도중 둘 중 한 명의 덱에 있는 카드의 수가 0개가 되는 즉시 게임 종료
        if (deck[turn].empty())
            break;

        //이번에 종을 칠 사람
        int bell = -1;
        if (card == 5) //카드가 5가 된다면
            bell = 0; //bell은 0이된다
        else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5))
            // 도도나 수연이의 턴에서그라운드가 비엇지 않고, 맨앞 카드와, 상대의 맨앞꺼의 합이 5가 된다면
            bell = 1; //bell은 1이된다

        if (bell != -1) { //누군가가 종을 쳤다면
            moveCard(deck[bell], ground[!bell]);
            moveCard(deck[bell], ground[bell]);
        }
        turn = !turn; //차례 바꾸기
    }
    return make_pair(deck[0].size(), deck[1].size());
}

/**
 * 1. 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용
 * 2. 게임을 진행하던 도중 언제든지 누군가의 카드 덱이 비게되면 게임을 종료
 */
int main() {
    int n, m, num1, num2;
    vector<deque<int>> deck(2), ground(2); // 덱과 그라운드 덱선언

    cin >> n >> m; // 카드의 개수와 게임 진행 횟수 입력 받기
    while (n--) { // 도도와 수연이 꺼 카드 입력 받고 덱에 저장
        cin >> num1 >> num2;
        deck[0].push_front(num1);
        deck[1].push_front(num2);
    }
    //반환 값 pair로 저장하기
    pair<int, int> result = playGame(m, deck, ground);
    //도도 수연의 카드 사이즈가 같다면 비긴경우
    if (result.first == result.second)
        cout << "dosu\n";
    //도도가 이겼다면
    else if (result.first > result.second)
        cout << "do\n";
    //수연이가 이겼다면
    else if (result.first < result.second)
        cout << "su\n";
}