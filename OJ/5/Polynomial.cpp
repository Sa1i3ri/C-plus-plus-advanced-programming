#include "Polynomial.h"
#include <assert.h>

Polynomial::Polynomial(const vector<int> &coefficients) {
  coefficients_ = coefficients;
}

Polynomial::Polynomial(const Polynomial &other) {
  this->coefficients_ = other.coefficients_;
}

void Polynomial::output() const {
    int max_exp = coefficients_.size() -1;
    for(int i = max_exp ; i>=0 ; i--){
        int j = max_exp - i;
        if(coefficients_[j] != 0){
            std::cout<< coefficients_[j]<< "";
            std::cout<< '('<< "";
            std::cout<< i<< "";
            std::cout<< ')'<< " ";
        }
    }
    std::cout<< "\n" << " ";

}

Polynomial add(const Polynomial &p1, const Polynomial &p2) {
    Polynomial *result = new Polynomial();
    int max_exp_p1 = p1.coefficients_.size()-1;
    int max_exp_p2 = p2.coefficients_.size()-1;
    if(max_exp_p1 > max_exp_p2){
        for(int i = 0;i<=max_exp_p1;i++){
            int curExp = max_exp_p1 - i;
            int curIndex = max_exp_p1 - curExp;
            if(curExp > max_exp_p2){
                result->coefficients_.push_back(p1.coefficients_[max_exp_p1 - curExp]);
            }else{
                result->coefficients_.push_back(p1.coefficients_[max_exp_p1 - curExp] + p2.coefficients_[max_exp_p2 - curExp]);
            }
        }
    }else{
            for(int i = 0;i<=max_exp_p2;i++){
            int curExp = max_exp_p2 - i;
            int curIndex = max_exp_p2 - curExp;
            if(curExp > max_exp_p1){
                result->coefficients_.push_back(p2.coefficients_[max_exp_p2 - curExp]);
            }else{
                result->coefficients_.push_back(p1.coefficients_[max_exp_p1 - curExp] + p2.coefficients_[max_exp_p2 - curExp]);
            }
        }
    }
    return *result;
}

Polynomial derivate(const Polynomial &p) {
    Polynomial *result = new Polynomial();
    int max_exp = p.coefficients_.size()-1;
    for(int i = 0;i< p.coefficients_.size();i++){
        int curExp = max_exp - i;
        result->coefficients_.push_back(curExp * p.coefficients_[i]);
    }
    result->coefficients_.erase(result->coefficients_.begin()+ result->coefficients_.size()-1);
    return *result;
}


int getMax(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}



int main(){
Polynomial t({1, 1, 1}); // x^2 + x + 1
derivate(t).output(); // 2x + 1
}

