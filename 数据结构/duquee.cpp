#include <iostream>
#include <vector>

using namespace std;

// 小根堆
class Dequee{
    private:
        vector<int> data;
        int tail;
    public:
        Dequee(int size){
            data.resize(size+1);
            data[0]=size+1;
            tail=1;
        }
    // 交换两个元素的值
    void exchange(int i,int j){
        int temp = data[i];
        data[i]=data[j];
        data[j]=temp;
    }
    // 入堆
        bool push(int val){
            if(tail>=data[0])
                return 0;
            data[tail++]=val;
            int temp = tail-1;
            while(temp!=1){
                if(data[temp]<data[temp/2]){
                    exchange(temp,temp/2);
                    temp = temp/2;
                }else
                    break;
            }
            return 1;
        }
    // 出堆
        int pop(){
            if(tail<1)
                return -1;
            int res = data[1];
            exchange(1,tail-1);
            tail--;
            data[tail]=0;
            int temp = 1;
            while(2*temp<tail){
                int maxVal = 2*temp;
                if(2*temp+1<tail && data[2*temp+1]<data[maxVal])
                    maxVal = 2*temp+1;
                if(data[temp]>data[maxVal]){
                    exchange(temp,maxVal);
                    temp = maxVal;
                }else
                    break;
            }
            return res;
        }
    // 返回堆顶元素
        int top(){
            if(tail<1)
                return -1;
            return data[1];
        }
        void print(){
            for(auto it:data)
                cout<<it<<" ";
            cout<<endl;
        }
};

int main(int argc, char const *argv[])
{
    vector<int> test = {4,7,2,7,3};
    Dequee* de = new Dequee(10);
    for(int i=0;i<test.size();i++){
        de->push(test[i]);
        de->print();
    }
    for(int i=0;i<test.size();i++){
        cout<<de->pop()<<endl;
        de->print();
    }   
    return 0;
}
