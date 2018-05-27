#include <iostream>
#include <vector>

using namespace std;

class Complex {
public:
    double ze;
    double re;

    Complex(double re, double ze) {
        this->ze = ze;
        this->re = re;
    };

    Complex &operator+(Complex &complex) {
        this->re += complex.re;
        this->ze += complex.ze;
        return *this;
    }

    Complex &operator+(double value) {
        this->re += value;
        return *this;
    }
    Complex &operator-(double value) {
        this->re -= value;
        return *this;
    }

    Complex &operator-(Complex &complex) {
        this->re -= complex.re;
        this->ze -= complex.ze;
        return *this;
    }

    Complex &operator*(Complex &complex) {
        this->re *= complex.re;
        this->ze *= -complex.ze;
        return *this;
    }
    Complex &operator*(double d) {
        this->re *= d;
        this->ze *= d;
        return *this;
    }
    Complex &operator/(double d) {
        this->re /= d;
        this->ze /= d;
        return *this;
    }
    void setValues(double a, double ze){
        this->re = a;
        this->ze = ze;
    }
    void toString(){
        if(this->ze!=0){
            if(this->ze>0){
                cout<<this->re<<"+"<<this->ze<<"i";

            }else {
                cout<<this->re<<this->ze<<"i";
            }

        }else{
            cout<<this->re;
        }
        cout << " ";
    }

};

class Vector2D {
public:
    vector<vector<Complex>> vec;

    Vector2D(int size) {
        for (int i = 0; i < size; i++) {
            vector<Complex> vector_temp;
            vec.push_back(vector_temp);
            for (int j = 0; j < size; j++) {
                double re, ze;
                cin >> re;
                cin >> ze;
                Complex complex(re, ze);
                vec[i].push_back(complex);
            };
        }
    }

    Vector2D &operator+(Vector2D &vec2) {
        for (int i = 0, sizeI = vec.size(); i < sizeI; i++) {
            for (int j = 0, sizeJ = vec[i].size(); j < sizeJ; j++) {
                vec[i][j] = vec[i][j] + vec2.vec[i][j];
            }
        }
        return *this;
    }

    Vector2D &operator-(Vector2D &vec2) {
        for (int i = 0, sizeI = vec.size(); i < sizeI; i++) {
            for (int j = 0, sizeJ = vec[i].size(); j < sizeJ; j++) {
                vec[i][j] = vec[i][j] - vec2.vec[i][j];
            }
        }
        return *this;
    }

     Vector2D& operator*(double t) {
        for(int i=0, sizeI = vec.size(); i < sizeI; i++) {
        for(int j = 0, sizeJ = vec[i].size(); j<sizeJ; j++) {
              vec[i][j]= vec[i][j] * t;
       }
     }
     return *this;
    }

    Vector2D &operator/(double t) {
        for (auto &i:vec) {
            for (auto &j:i) {
                j=j/t;
            }
        }
        return *this;
    }

    void toString() {
        for (auto &i:vec) {
            for (auto &j:i) {
                j.toString();
            }
            cout << endl;
        }
    }
};

int main() {
    Vector2D vector2D(2);
//    Vector2D vector2D1(2);
//    vector2D = vector2D - vector2D1;
//    vector2D.toString();
    vector2D = vector2D / 6;
    vector2D.toString();
//    Complex complex(12,77);
//    complex.toString();
    return 0;
}