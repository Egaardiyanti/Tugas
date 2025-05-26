#include <iostream>
#include <cmath> 
using namespace std;

float rata (int x[], int N){
	float total = 0;
	for (int i = 0; i<N; i++){
		total +=x[i];
	}
	return total/N;
}

long sqr (int n){
	return n*n;

}

float STD(const int x[], int N, float rata) {
    float jumlah = 0;
    for (int i = 0; i < N; i++) {
        jumlah += sqr(x[i] - rata);
    }
    return sqrt(jumlah / (N - 1));
}

int main(){
	int N;
	
	cout << "Masukkan jumlah data : ";
	cin >> N;
	
	int x[N];
	
   cout << "Masukkan " << N << " data :"<<endl;
    for (int i = 0; i < N; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> x[i];
    }
    float r = rata(x, N);
    float std_deviasi = STD(x, N, r);

    cout << "\nRata-rata: " << r << endl;
    cout << "Deviasi standar: " << std_deviasi << endl;

    return 0;
}
