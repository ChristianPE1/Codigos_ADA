#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int withdraw(vector<int>& monedas, int i, int max, int cont) {
    if (i == monedas.size())
        return cont;

    if (monedas[i] + max < monedas[i + 1])
        return withdraw(monedas, i + 1, max + monedas[i], cont + 1);
    
    return withdraw(monedas, i + 1, max, cont);
}

int main() {
    int numVectors;
    cin >> numVectors;

    for (int i = 0; i < numVectors; i++) {
        int size;
        cin >> size;

        vector<int> vec(size);

        for (int j = 0; j < size; j++) {
            cin >> vec[j];
        }
        sort(vec.begin(), vec.end());
        int maxCoins = withdraw(vec, 1, vec[0], 1);
        cout << maxCoins << endl;
    }

    return 0;
}
