
class Account{
    /*封装起来，用户不应该也不能随意调整下面的成员变量*/
    private:
    char* username;
    char* accountNum;
    int deposit;

    public:
    Account();
    char* getUserNmae();
    char* getAccountNum();
    int getDeposit();
    /*返回存入或取出后的存款金额*/
    int save();
    int withdraw();

};