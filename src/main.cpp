#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <array>

using namespace std;

struct matrix
{
    string name;             // نگه داشتن نام ماتریس
    int row;               // نگه داشتن سطر ماتریس
    int clu;               // نگه داشتن ستون ماتریس
    vector<vector<int>> int_array;  //نگه داری درایه های ماتریس با نوع عدد صحیح
    vector<vector<float>> float_array; //  نگه داری درایه های ماتریس با نوع عدد اعشاری
    vector<vector<char>> char_array; // نگه داری ماتریس از نوع کاراکتر
    vector<vector<string>> string_array; // نگهداری ماتریس از نوع رشته
    int count = 0;   //  متغییر کمکی برای تشخیص نوع ارایه   
};

typedef struct matrix mat;

void add(string com, vector<mat>&matric);
bool upper_triangular(string com, vector<mat>&matric);
bool lower_triangular(string com, vector<mat>&matric);
void triangular(string com, vector<mat>&matric);
void show(string com, vector<mat>&matric);
void change(string com, vector<mat>&matric);
void diagonal(string com, vector<mat>&matric);
void identity(string com, vector<mat>&matric);
void deletee(string com, vector<mat>&matric);

void menu()
{
    cout << "+----------------------------------+" << endl; 
    cout << "|           add matrix             |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "|           is_diagonal            |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "|       is_upper_triangular        |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "|       is_lower_triangular        | "<< endl;
    cout << "+----------------------------------+ "<< endl;
    cout << "|          is_triangular           | "<< endl;
    cout << "+----------------------------------+ "<< endl;
    cout << "|          is_identity             | "<< endl;
    cout << "+----------------------------------+ "<< endl;
    cout << "|              show                | "<< endl;
    cout << "+----------------------------------+ "<< endl;
    cout << "|             deletee              | "<< endl;
    cout << "+----------------------------------+ "<< endl;
    cout << "|             change               | "<< endl;
    cout << "+----------------------------------+ "<< endl;
}

void commands(vector<mat>&matric) // گرفتن دستور
{
    string com; // متغیر برای دریافت دستور
    cout << "pleas enter your command" << endl;
    getline(cin, com);

    string del = " "; 
    string spl; // متغییر کمکی برای بخش بخش کردن دستور
    
    spl = com.substr(0, com.find(del));  // جدا کردن قسمت اول رشته وارد شده

    if(spl == "add")
    {
        add(com,matric); // تابع اضافه کردن مانربس
    }
    else if(spl == "is_diagonal")
    {
        diagonal(com,matric); // تابع قطری بودن
    }
    else if(spl == "is_upper_triangular")
    {
        upper_triangular(com, matric); // تابع بالا مثلثی
    }
    else if(spl == "is_lower_triangular")
    {
        lower_triangular(com, matric); // تابع پایین مثلثی
    }
    else if(spl == "is_triangular")
    {
        triangular(com, matric); // تابع مثلثی
    }
    else if(spl == "is_identity")
    {
        identity(com, matric); // تابع همانی بودن
    }
    else if(spl == "show")
    {
        show(com, matric); // تابع چاپ
    }
    else if(spl == "deletee")
    {
        deletee(com, matric); // تابع حذف
    }
    else if(spl == "change")
    {
        change(com, matric); // تابع تغییر مقدار درایه
    }
    else
    {
        cout << "your command is not correct , pleas enter again" << endl;
        commands(matric);
    }
}

void add(string com, vector<mat>&matric) // اضافه کردن ماتریس
{
    mat m; // تعریف یک متغییر از استراکت
    int len = com.length(); // نگهداری طول رشته دستور
    string mtr; // متغییر کمکی برای نگهداری درایه های ماتریس
    string spi; // متغییر کمکی برای نگه ذاری فسمت های جدا شده رشنه
    string del = " ";
    if(strncmp(&com[0], "add matrix", 11) == 0)
    {
        for(int i = 0; i < 6; i++)
        {
            spi = com.substr(0, com.find(del)); // جدا کردن قسمت هایی از رشته که با فاصله جدا شده اند
            if(i == 2)
            {
                m.name = spi; // جدا کردن قسمت اسم ماتریس
                spi.clear(); // خالی کردن رشته
            }
            if(i == 3)
            {
                m.row = stoi(spi); // تبدیل رشنه به عدد صحیح و جدا کردن مقذار سطز ماتریس از رشته
                spi.clear();
            }
            if(i == 4)
            {
                int sti = stoi(spi); // تبدیل رشته جدا شده به عدد صحیح
                if(isdigit(sti)) // چک کردن رقم بودن مقدار ستون
                {
                    m.clu = sti; 
                }
                else  // اگر رقم نباشد براکت است و سطر و ستون ماتریس برابرند
                {
                    m.clu = m.row;
                }
                spi.clear();
            }
            if(i == 5)
            {
                int len = spi.length(); // نگهداری طول ماتریس
                spi[0] = '\0';
                spi[len - 1] = '\0'; // حذف خونه اول و اخر رشنه که حاوی براکت
                mtr = spi; // نگهداری درایه ها در رشنه جدید
                spi.clear();
            }
        }
        
        int len2 = mtr.length(); // نگهداری زوا رشته حاوی درایه ها
        for(int i = 0; i < len2; i++)
        {
            string del2 = ",";
            spi = com.substr(0, com.find(del2)); // جدا سازی درایه های ماتریس

            int sti = stoi(spi); // تبدیل رشته به عدد

            if(isdigit(sti)) // چک کردن این که حاوی عدد است یا نه
            {
                char ch = '.';
                if(strchr(&spi[0], ch)) // سرچ کردن . در رشته
                    m.float_array;
                    m.count = 2; // اگر نوع درایه های ماتریس عدد اعشاری بود عدد 2 را می دهیم
                }
                else
                {
                    m.int_array;
                    m.count = 1; // اگر نوع درایه های ماتریس عدد اعشاری بود عدد 1 را به ان انتصاب می دهیم
                }
            }
            if((isalpha(spi[0])) & (len2 > 1)) // چک کردن برای ایم که کراکتر است یا رشته
            {
                m.string_array;
                m.count = 4; // اگر نوع درایه های ماتریس رشته بود عدد 4 را به ان انتصاب می دهیم
            }
            else
            {
                m.char_array;
                m.count = 3; // اگر نوع درایه های ماتریس کاراکتر بود عدد 3 را به ان می دهیم
            }
            spi.clear();
        }
    } 
    matric.push_back(m); // ریختن محتوای استراکت در وکتور
}

void diagonal(string com, vector<mat>&matric) // قطری بودن
{
    int diagonal = 1; // متغییر کمکی
    string name2; // نگهداری اسم ماتریس وارد شده
    string del = " ";
    for(int i = 0; i < 2; i++)
    {
        name2.clear();
        name2 = com.substr(0, com.find(del)); // جدا سازی اسم ماتریس وارد شده
    }

    for(int i = 0; i < matric.size() ; i++)
    {
        if(matric[i].name == name2) // پیدا کردن خونه مانریس مورد نظر
        {
            if(matric[i].row == matric[i].clu) // چک کردن برابری سطر و ستون
            {
                for(int j = 0; j < matric[i].row; j++)
                {
                    for(int k = 0; k < matric[i].clu ; k++)
                    {
                        if(matric[i].count == 1)
                        {
                            // فرض می کنیم ماتریس قطری است و اگر خلاف ان ثابت شد نه را نشان می دهیم
                            if((k != j) && (matric[i].int_array[j][k] != 0)) 
                            {
                                diagonal = 0;
                            }
                        }
                        if(matric[i].count == 2)
                        {
                            if((k != j) && (matric[i].float_array[j][k] != 0))
                            {
                                diagonal = 0;
                            }
                        }
                        if(matric[i].count == 3)
                        {
                            if((k != j) && (matric[i].char_array[j][k] != 0))
                            {
                                diagonal = 0;
                            }
                        }
                        if(matric[i].count == 4)
                        {
                            if((k != j) && (matric[i].string_array[j][k] != "0"))
                            {
                                diagonal = 0;
                            }
                        }
                    }
                }
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "The imported matrix is not found" << endl;
        }
    }
    if(diagonal == 1)
    {
        cout << "YES" << endl;
    }
    if(diagonal == 0)
    {
        cout << "NO" << endl;
    }
}

bool upper_triangular(string com, vector<mat>&matric) // بالا مثلثی
{
    int upper = 1; // متغییر کمکی

    string name2;
    string del = " ";
    for(int i = 0; i < 2; i++)
    {
        name2.clear();
        name2 = com.substr(0, com.find(del)); // جدا سازی اسم ماتریس وارد شده
    }

    for(int i = 0; i < matric.size() ; i++)
    {
        if(matric[i].name == name2) // پیدا کردن خونه مانریس مورد نظر
        {
            if(matric[i].row == matric[i].clu) // چک کردن برابری سطر و ستون
            {
                for(int j = 0; j < matric[i].row; j++)
                {
                    for(int k = 0; k < matric[i].clu ; k++)
                    {
                         if(matric[i].count == 1)
                        {
                            //    فرض می کنیم ماتریس بالا مثلثی است و اگر خلاف ان ثابت شد مقدار متغییر کمکی را تغییر می دهیم
                            if((k < j) && (matric[i].int_array[j][k] != 0))
                            {
                                upper = 0;
                                break;
                            }
                        }
                        if(matric[i].count == 2)
                        {
                            if((k < j) && (matric[i].float_array[j][k] != 0))
                            {
                                upper = 0;
                                break;
                            }
                        }
                        if(matric[i].count == 3)
                        {
                            if((k < j) && (matric[i].char_array[j][k] != 'a'))
                            {
                                upper = 0;
                                break;
                            }
                        }
                        if(matric[i].count == 3)
                        {
                            if((k < j) && (matric[i].string_array[j][k] != "aa"))
                            {
                                upper = 0;
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                cout << "The imported matrix is not diagonal and can not be triangular" << endl;
            }
        }
        else
        {
            cout << "The imported matrix is not found" << endl;
        }
    }

    if(upper == 1) // اگر مقدار متغییر کمکی تغییر نکرد درست را بر می گردانیم
    {
        return true;
    }
    else // در غیر این صورت بالا مثلثی نبوده و غلط را بر می گردانیم
    {
        return false;
    }
}

bool lower_triangular(string com, vector<mat>&matric) // پایین مثلثی
{
    int lower = 1; // متغییر کمکی

    string name2; // نگهداری اسم ماتریس مورد نظر
    string del = " ";
    for(int i = 0; i < 2; i++)
    {
        name2.clear();
        name2 = com.substr(0, com.find(del)); // جدا سازی اسم ماتریس موردنظر از رشته
    }

    for(int i = 0; i < matric.size() ; i++)
    {
        if(matric[i].name == name2) // پیدا کردن خونه مانریس مورد نظر 
        {
            if(matric[i].row == matric[i].clu) //  چک کردن برابری سطر و ستون
            {
                for(int j = 0; j < matric[i].row ; j++)
                {
                    for(int k = 0; k < matric[i].clu ; k++)
                    {
                        if(matric[i].count == 1)
                        {
                            // فرض می کنیم ماتریس پایین مثلثی است و اگر خلاف ان ثابت شد مقدار متغییر کمکی را تغییر می دهیم
                            if((k > j) && (matric[i].int_array[j][k] != 0))
                            {
                                lower = 0;
                                break;
                            }
                        }
                        if(matric[i].count == 2)
                        {
                            if((k > j) && (matric[i].float_array[j][k] != 0))
                            {
                                lower = 0;
                                break;
                            }
                        }
                        if(matric[i].count == 3)
                        {
                            if((k > j) && (matric[i].char_array[j][k] != 'a'))
                            {
                                lower = 0;
                                break;
                            }
                        }
                        if(matric[i].count == 3)
                        {
                            if((k > j) && (matric[i].string_array[j][k] != "aaa"))
                            {
                                lower = 0;
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                cout << "The imported matrix is not diagonal and can not be triangular" << endl;
            }
        }
        else
        {
            cout << "The imported matrix is not found" << endl;
        }
    }

    if(lower == 1) // اگر مقدار متغییر کمکی تغییر نکرد درست را بر می گردانیم 
    {
        return true;
    }
    else // در غیر این صورت بالا مثلثی نبوده و غلط را بر می گردانیم
    {
        return false;
    }
}

void triangular(string com, vector<mat>&matric) // مثلثی بودن
{
    bool upper = upper_triangular(com,matric); // فراخوانی تابع و نگهداری مقذار برگرداننده شده در متغییر کمکی
    bool lower = lower_triangular(com, matric); //   فراخوانی تابع و نگهداری مقذار برگرداننده شده در متغییر کمکی

    string name2;
    string del = " ";
    for(int i = 0; i < 2; i++)
    {
        name2.clear();
        name2 = com.substr(0, com.find(del));  // جدا سازی اسم ماتریس موردنظر از رشته
    }

    for(int i = 0; i < matric.size() ; i++)
    {
        if(matric[i].name == name2) //  پیدا کردن خونه مانریس مورد نظر
        {
            if((upper == true) & (lower == false))
            {
                cout << "This matrix is upper triangular" << endl;
            }
            if((lower == true) & (upper == false))
            {
                cout << "This matrix is lower triangular" << endl;
            }
            if((upper == true) & (lower == true))
            {
                cout << "This matrix is triangular" << endl;
            }
            if((upper == false) & (lower == false))
            {
                cout << "This matrix is not triangular" << endl;
            }
        }
    }
}

void identity(string com, vector<mat>&matric) // همانی بودن 
{
    int identity = 0; // متغییر کمکی 
    string name2;
    string del = " ";
    for(int i = 0; i < 2; i++)
    {
        name2.clear();
        name2 = com.substr(0, com.find(del));  // جدا سازی اسم ماتریس موردنظر از رشته
    }

    for(int i = 0; i < matric.size() ; i++)
    {
        if(matric[i].name == name2)  //  پیدا کردن خونه مانریس مورد نظر
        {
            if(matric[i].row == matric[i].clu) // چک کردن برابری سطر و ستون
            {
                for(int j = 0; j < matric[i].row; j++)
                {
                    for(int k = 0; k < matric[i].clu ; k++)
                    {
                       if(matric[i].count == 1)
                        {
                            // فرض می کنیم ماتریس همانی است و اگر خلاف ان ثابت شد مقدار متغییر کمکی را تغییر می دهی
                            if((k == j) && (matric[i].int_array[j][k] == 1))
                            {
                                identity = 1;
                                break;
                            }
                        }
                        if(matric[i].count == 2)
                        {
                            if((k == j) && (matric[i].float_array[j][k] == 1))
                            {
                                identity = 1;
                                break;
                            }
                        }
                        if(matric[i].count == 3)
                        {
                            if((k == j) && (matric[i].char_array[j][k] == 1))
                            {
                                identity = 1;
                                break;
                            }
                        }
                        if(matric[i].count == 3)
                        {
                            if((k == j) && (matric[i].string_array[j][k] == "1"))
                            {
                                identity = 1;
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                cout << "The imported matrix is not diagonal" << endl;
            }
        }
        else
        {
               cout << "The imported matrix is not found" << endl;
        }
    }
    if(identity == 1) //  اگر مقدار متغییر کمکی تغییر نکرد درست را بر می گردانیم
    {
        cout << "YES" << endl;
    }
    if(identity == 0) // در غیر این صورت بالا مثلثی نبوده و غلط را بر می گردانیم
    {
        cout << "NO" << endl;
    }
}

void show(string com, vector<mat>&matric) // تابع چاپ
{
    string name2;
    string del = " ";
    for(int i = 0; i < 2; i++)
    {
        name2.clear();
        name2 = com.substr(0, com.find(del));  // جدا سازی اسم ماتریس موردنظر از رشته
    }

    for(int i = 0; i < matric.size() ; i++)
    {
        if(matric[i].name == name2) // پیدا کردن خونه مانریس مورد نظر
        {
            if(matric[i].count == 1)
            {
                for(int j = 0; j < matric[i].row ; j++)
                {
                    for(int k = 0; k < matric[i].clu ; k++)
                    {
                        cout << matric[i].int_array[j][k] << "\t"; // چاپ درایه به درایه
                    }
                    cout << endl;
                }
            }
            if(matric[i].count == 2)
            {    
                for(int j = 0; j < matric[i].row ; j++)
                {
                    for(int k = 0; k < matric[i].clu ; k++)
                    {
                        cout << matric[i].float_array[j][k] << "\t";
                    }
                    cout << endl;
                }    
            }
            if(matric[i].count == 3)
            {
                for(int j = 0; j < matric[i].row ; j++)
                {
                    for(int k = 0; k < matric[i].clu ; k++)
                    {
                        cout << matric[i].char_array[j][k] << "\t";
                    }
                    cout << endl;
                }
            }
            if(matric[i].count == 4)
            {
                for(int j = 0; j < matric[i].row ; j++)
                {
                    for(int k = 0; k < matric[i].clu ; k++)
                    {
                        cout << matric[i].string_array[j][k] << "\t";
                    }
                    cout << endl;
                }
            }
        }
        else
        {
               cout << "The imported matrix is not found" << endl;
        }
    }
}

void deletee(string com, vector<mat>&matric)  // حذف کردن
{
     string name2;
     string del = " ";
     for(int i = 0; i < 2; i++)
     {
          name2.clear();
          name2 = com.substr(0, com.find(del)); //  جدا سازی اسم ماتریس موردنظر از رشته
     }

     for(int i = 0; i < matric.size() ; i++)
     {
          if(matric[i].name == name2) //  پیدا کردن خونه مانریس مورد نظر
          {
               matric.erase(matric.begin() + (i - 1)); // حذف خونه مورد نظر
          }
          else
          {
               cout << "The imported matrix is not found" << endl;
          }
     }
}

void change(string com, vector<mat>&matric) // تغییر دادن درایه
{
    string name2; // نگهداری اسم ماتریس مورد نظر
    int row2; // نگهداری شماره سطری  که نیاز به تغییر دارد
    int clu2;  // نگهداری شماره ستونی که نیاز به تغییر دار
    string chng; // نگهداری مقدار جدید

    string del = " ";
    for(int i = 0; i < 5; i++)
    {
        if(i == 1)
        {
            name2 = com.substr(0, com.find(del)); // جداسازی اسم
        }
        if(i == 2)
        {
            row2 = stoi(com.substr(0, com.find(del))); // جداسازی سطر
        }
        if(i == 3)
        {
            clu2 = stoi(com.substr(0, com.find(del))); // جداسازی ستون
        }
        if(i == 4)
        {
            chng = com.substr(0, com.find(del)); // جدا سازی مقدار جدید
        }
        name2.clear();
    }

    for(int i = 0; i < matric.size() ; i++)
    {
        if(matric[i].name == name2)   // پیدا کردن خونه مانریس مورد نظر
        {
            if(matric[i].count == 1)
            {
                int spl = stoi(chng);
                matric[i].int_array[row2][clu2] = spl;
            }
            if(matric[i].count == 2)
            {
                float spl2 = stoi(chng);
                matric[i].float_array[row2][clu2] = spl2;
            }
            if(matric[i].count == 3)
            {
                matric[i].char_array[row2][clu2] = chng[0];
            }
            if(matric[i].count == 4)
            {
                 matric[i].string_array[row2][clu2] = chng;
            }
        }
        else
        {
             cout << "The imported matrix is not found" << endl;
        }
    } 
}

int main()
{

    vector<mat> matric; // وکتور اصلی

    while(1)
    {
          menu(); // نابع منو 
          commands(matric); // تابع گرفتن دستور
    }

    return 0;
}