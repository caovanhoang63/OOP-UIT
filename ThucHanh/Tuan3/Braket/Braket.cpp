#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

typedef std::complex<double> complexd;

class matrix
{
// 1 scalar  , 2 bra , 3 matrix,  4 ket.
public:
    std::vector<std::vector<complexd>> elements;
    int type;
    matrix(int row) {
        this->elements.resize(row);
        for (std::vector<complexd>& x : elements)
            x.resize(row);
    }
    matrix(int type, int row) {
        switch (type)
        {
        case 1: 
        {
            elements.resize(1);
            elements[0].resize(1);
            break;
        }
        case 2: 
        {
            elements.resize(1);
            elements[0].resize(row);
            break;
        }
        case 3:
            this->elements.resize(row);
            for (std::vector<complexd>& x : elements)
                x.resize(row);
            break;
        }
    }
    matrix(){}
    matrix conjugate()
    {
        matrix result;
        for (int i = 0; i<elements.size();i++)
        {
            std::vector<complexd> temp;
            for(int j = 0 ; j < elements[i].size();j++){
                temp.push_back(std::conj(elements[i][j]));
            }
            result.elements.push_back(temp);   
        }
        return result;
    }
    matrix Trans(){
        matrix result(elements.size());
        for (int i = 0; i < elements.size(); i++) {
            for (int j = 0; j < elements.size(); j++) {
                result.elements[j][i] = elements[i][j];
            }
        }
        return result;
    }
    matrix Mul(matrix temp) {
        matrix result(this->elements.size());
        for (int i = 0; i < elements.size(); i++) {
            for (int j = 0; j < elements.size(); j++) {
                complexd sum = 0;
                for (int z = 0; z < elements.size(); z++) {
                    sum += this->elements[i][z] * temp.elements[z][j];
                }
                result.elements[i][j] = sum;
            }
        }
        return result;
    }
    static matrix innerProduct(matrix vector1,matrix vector2) {
        matrix temp = vector2.Trans();
        temp.conjugate();
        matrix result = vector1.Mul(temp);
        result.type = 1;
        return result;
    }
    static matrix tensorProduct(matrix a, matrix b) {
        matrix result(a.elements.size() * b.elements.size());
        int z = 0;
        for (int i = 0; i < a.elements[0].size(); i++) {
            for (int j = 0; j < b.elements[0].size(); j++) {
                result.elements[z++][0] = a.elements[i][0] * b.elements[j][0];
            }
        }
        return result;
    }
    void enter_matrix() {
        for (int i = 0; i < elements.size(); i++) {
            for (int j = 0; j < elements.size(); j++) {
                complexd x;
                std::cin >> x;
                elements[i][j] = x;
            }
        }
    }
    void enter_vector() {
        for (int i = 0; i < elements.size(); i++) {
            double real, imag;
            std::cin >>real>>imag ;
            complexd x(real, imag);
            elements[0][i] = x;
        }
    }
    void enter_scalar() {
        double real, imag;
        std::cin >> real >> imag;
        complexd x(real, imag);
        elements[0][0] = x;
    }
    void print() {
        for (int i = 0; i < elements.size(); i++) {
            for (int j = 0; j < elements.size(); j++) {
                std::cout<< elements[i][j]<<" ";
            }
            std::cout << std::endl;
        }
    }
    void print_scalar() {
        std::cout << elements[0][0].real() << " " << elements[0][0].imag();
    }
};
class Calculator {
public:
    std::string cal;
    std::vector<matrix> list;
    void enter_list() {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int type;
            std::cin >> type;
            switch (type)
            {
            case 1: 
            {
                matrix temp(type,1);
                temp.enter_scalar();
                list.push_back(temp);
                break;
            }
            case 2:
            {
                int x;
                std::cin >> x;
                matrix temp(type,x);
                temp.enter_vector();
                list.push_back(temp);
                break;
            }
            case 3: 
            {
                int x;
                std::cin >> x;
                matrix temp(type,x);
                temp.enter_matrix();
                list.push_back(temp);
                break;
            }
            }
        }
    }
    void enter() {
        std::cin >> cal;
    }
    matrix process() {
        std::vector<matrix> result;
        matrix Result;
        int Size = cal.size();
        for (int i = 0; i < Size; i++) {
            if (cal[i] == '|' && cal[i + 2] == '>') {
                result.push_back(list[cal[i + 1] - 'a'].Trans());
                i = i + 2;
            }
            else if (i > 0 && cal[i - 1] == '|' && cal[i + 1] == '>') {
                result.push_back(list[cal[i] - 'a'].Trans());
                i = i + 1;
            }
            else if (cal[i] == '<') {
                result.push_back(list[cal[i + 1] - 'a']);
                i = i + 2;
            }
            else if (cal[i] == '|' && cal[i + 2] == '|') {
                result.push_back(list[cal[i + 1] - 'a']);
                i = i + 2;
            }
            else if (i > 0 && cal[i - 1] == '|' && cal[i + 1] == '|') {
                result.push_back(list[cal[i] - 'a']);
                i = i + 1;
            }
            else
                result.push_back(list[cal[i] - 'a']);
        }
        Result = result[0];
        for (int i = 1; i < result.size(); i++) {
            
        }


    }
};
int main()
{
    matrix a(2, 2);
    a.enter_vector();
    matrix b(2, 2);
    b.enter_vector();
    (matrix::innerProduct(a,b)).print();
    return 0;
}
