#include <iostream>
#include <functional>
using namespace std;

double reduce (int* arr, const unsigned n, function<double(double, int)> aggregator) {
    double result = arr[0];
    for (auto k=1U; k < n; ++k) {
        result = aggregator(result, arr[k]);
    }
    return result;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    const unsigned N = sizeof(a) / sizeof(a[0]);

    for(int i=0;i<N;i++)
        cout << "a[" << i << "]=" << a[i] << endl;

    auto sum = reduce(a, N, [] (auto acc, auto n) {return acc+n;});
    auto prod = reduce(a, N, [] (auto acc, auto n) {return acc*n;});
    auto max = reduce(a, N, [] (auto acc, auto n) {return n > acc? n : acc;});
    auto min = reduce(a, N, [] (auto acc, auto n) {return n < acc? n : acc;});

    cout << "sum : " << sum << endl;
    cout << "prod: " << prod << endl;
    cout << "max : " << max << endl;
    cout << "min : " << min << endl;

    return 0;
}

