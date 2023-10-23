#include "Vector.h"
#include <iostream>

void Vector::output() const {
    int len = this->vec_.size();
    for(int i = 0;i<len;i++){
        if(i==len-1){
            std::cout<< this->vec_[i] << "\n";
        }else{
            std::cout<< this->vec_[i] << " ";
        }

    }
}

Vector Vector::map(map_func f) const {
    Vector *result = new Vector();
    for(int i =0;i<this->vec_.size();i++){
        result->vec_.push_back(f(this->vec_[i]));
    }
    return *result;
}

Vector Vector::filter(filter_func f) const {
    Vector *result = new Vector();
    for(int i =0;i<this->vec_.size();i++){
        if(f(this->vec_[i])){
            result->vec_.push_back(this->vec_[i]);
        }
    }
    return *result;
}

Vector &Vector::for_each(map_func f) {
    for(int i =0;i<this->vec_.size();i++){
        this->vec_[i] = f(this->vec_[i]);
    }
    return *this;
}



// map func
int neg(int x) { return -x; }
// filter func
bool is_neg(int x) { return x < 0; }

int main(){
Vector foo({-1, -2, 0, 1, 3});
foo.map(neg).filter(is_neg).output();
foo.filter(is_neg).output(); 

}
