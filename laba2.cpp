#include <iostream> 
#include <cmath>
using namespace std;

// Функция для ввода int
int int_num()
{
    int number;
    std::cout << "Write number: ";
    std::cin >> number;
    
    if (!std::cin)
    {
        std::cout << "Error, wrong input" << std::endl;
    }
    else
    {
        return number;
    }
}

/* Дан набор целых чисел с четным количеством элементов. Заполнить вектор V исходными
числами, вывести вначале вторую половину элементов вектора V, а затем первую половину (в
каждой половине порядок элементов не изменять).*/
#include <vector>
int vector1()
{
    //Create vector
    int size;
    cout << "Write size vector" << endl;
    size = int_num();

    vector<int> vec1;
    if (size % 2 == 0)
    {
        cout << "Write number set" << endl;
        for (int i = 0; i < size; i++)
            vec1.push_back(int_num());
        
        //Output vector
        for (int it = vec1.size()/2; it < vec1.size(); ++it)
            cout << vec1.at(it) << " ";
        cout << endl;
        for (auto it = vec1.begin(); it != vec1.end() - vec1.size()/2; ++it)
            cout << *it << " ";
        cout << endl;
    }
    else
    {
        cout << "Wrong size";
    }

    return 0;
}

/* Дан список L, количество элементов которого делится на 3. Добавить в конец списка первую
треть его исходных элементов в обратном порядке. Использовать один вызов функции-члена insert. */
#include <list>
void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it << " ";
    cout << '\n';
}

int list1()
{
    //Create list
    int size;
    cout << "Write size list" << endl;
    size = int_num();

    list<int> list1;
    if (size % 3 == 0)
    {
        cout << "Write number set" << endl;
        for (int i = 0; i < size; i++)
            list1.push_back(int_num());

        //Output list
        cout << "Original list" << endl;
        showlist(list1);

        list<int> list2;
        for (int i = 0; i < size/3; i++)
        {
            list2.push_back(list1.front());
            list1.pop_front();
        }
        
        list2.reverse();

        auto it_last = list1.cend();
        list1.splice(it_last, list2);

        cout << "Change list" << endl;
        showlist(list1);
    }
    else
    {
        cout << "Wrong size";
    }

    return 0;
}

/* Дан список L с элементами A1, A2, A3, …, AN−1, AN (N — четное). Изменить порядок элементов в
списке на следующий: AN, A1, AN−1, A2, AN−2, …, AN/2, AN/2−1. Для этого использовать два
итератора i и r, связав их с первым и последним элементом списка. В цикле, который должен
повторяться N/2 раз, вызывать функцию-член splice с первым параметром i++ и третьим
параметром r-- */
int list2()
{
     //Create list
    int size;
    cout << "Write size list" << endl;
    size = int_num();

    
    if (size % 2 == 0)
    {
        list<int> list1;
        for (int i = 1; i <= size; i++)
            list1.push_back(i);
        showlist(list1);

        list<int> :: iterator i;
        list<int> :: iterator r;

        i = list1.begin();
        i--;
        r = list1.end();

        //Output list
        for (int j = 0; j < size/2; j++)
        {
            list1.splice(i++, list1, r--);
        }

        showlist(list1);
    }
    else
    {
        cout << "Wrong input" << endl;
    }

    return 0;
}

/* Дан набор символов. Вывести все символы из исходного набора в том же порядке, заменяя
цифровые символы на символ подчеркивания. Использовать алгоритм replace_copy_if. */
inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
   char * p;
   strtol(s.c_str(), &p, 10);
   return (*p == 0);
}
#include <algorithm>
int replace1()
{
    //Create vector
    int size;
    cout << "Write size vector: ";
    cin >> size;
    vector<string> vec1;
    for (int i = 0; i < size; i++)
        {
            string a;
            cout << "Write kit element: " ;
            cin >> a;
            vec1.push_back(a);
        }

    cout << "Original vector" << endl;
    for (string elem1 : vec1)
    {
        cout << elem1 << " ";
    }
    cout << "\n";

    vector<string> vec2;
    vec2.resize(vec1.size());
    replace_copy_if(vec1.begin(), vec1.end(), vec2.begin(), isInteger, (string)"_");  

    cout << "Change vector" << endl;
    for (string elem2 : vec2)
    {
        cout << elem2 << " ";
    }

    return 0;
}

/* Дан вектор V. Удалить второй из элементов вектора, равных нулю. Если нулевых элементов
меньше двух, то вектор не изменять. Использовать два вызова алгоритма find и функцию-член
erase. */
int findValue (const std::vector<int>& data, int value = 0)
{
    auto result{ std::find(begin(data), end(data), value) };
    if (result != end(data))
        return (result - begin(data) + 1);
}

int vector3()
{
    //Create vector
    int size;
    cout << "Write size vector: ";
    cin >> size;
    vector<int> vec1;
    for (int i = 0; i < size; i++)
        {
            int a;
            cout << "Write kit element: ";
            cin >> a;
            vec1.push_back(a);
        }

    cout << "Original vector" << endl;
    for (int elem1 : vec1)
    {
        cout << elem1 << " ";
    }
    cout << "\n";

    //Output vector
    cout << "Change vector" << endl;

    int pos1;
    pos1 = findValue(vec1);
    if (pos1 != 0)
    {
        vector<int> vec2;
        for (int i=0; i<vec1.size(); i++)  
            vec2.push_back(vec1[i]);
        vec2.erase(vec2.begin() + pos1 - 1);
        int pos2 = findValue(vec2);
        if (pos2 != 0)
        {
            vec1.erase(vec1.begin() + pos2);
        }
    }

    for (int elem1 : vec1)
    {
        cout << elem1 << " ";
    }

    return 0;
}

/* Даны числа A и B и векторы V1 и V2, каждый из которых содержит не менее 10 элементов.
Заполнить первые 5 элементов каждого вектора значениями A, а последние 5 — значениями B.
При преобразовании вектора V1 использовать два вызова алгоритма fill, при преобразовании
вектора V2 использовать два вызова алгоритма fill_n. */
int two_vector1()
{
    int A, B;
    cout << "Number A" << endl;
    A = int_num();
    cout << "Number B" << endl;
    B = int_num();

    //Create vector
    int size;
    vector<int> vec1, vec2;
    cout << "Write size 1st vector: " << endl;
    size = int_num();
    if (size >= 10)
    {
        for (int i = 0; i < size; i++)
            {
                int a;
                cout << "Write kit element: ";
                cin >> a;
                vec1.push_back(a);
            }
        //Create 2nd vector
        cout << "Write size 2nd vector: " << endl;
        size = int_num();
        if (size >= 10)
        {
            for (int i = 0; i < size; i++)
            {
                int a;
                cout << "Write kit element: ";
                cin >> a;
                vec2.push_back(a);
            }

            cout << "Original vectors" << endl;
            for (int elem1 : vec1)
            {
                cout << elem1 << " ";
            }
            cout << "\n";
            for (int elem1 : vec2)
                {
                    cout << elem1 << " ";
                }
            cout << "\n";

            //Output change vector
            fill(vec1.begin(), vec1.begin() + 5, A);
            fill(vec1.end() - 5, vec1.end(), B);
            
            fill_n(vec2.begin(), 5, A);
            fill_n(vec2.end() - 5, 5, B);

            cout << "Changed vectors" << endl;
            for (int elem1 : vec1)
                {
                    cout << elem1 << " ";
                }
            cout << "\n";

            for (int elem1 : vec2)
                {
                    cout << elem1 << " ";
                }
            cout << "\n";

        }
         else
        {
            cout << "Wrong input";
        }
    }
    else
    {
        cout << "Wrong input";
    }

    return 0;    
}

/* Дан дек D, элементами которого являются английские слова. Отсортировать его элементы по
убыванию их длин, а элементы одинаковой длины — в алфавитном порядке. Использовать
единственный вызов алгоритма sort с параметром — функциональным объектом, включающим
как сравнение строк, так и сравнение их длин. */
#include <deque>
//Show deque
void showdq(deque<string> d)
{
    deque<string>::iterator it;
    for (it = d.begin(); it != d.end(); ++it)
        cout << *it << " ";
    cout << '\n';
}

bool comp(const std::string& left, const std::string& right) 
{   
    if (left.length() == right.length())
        return left < right;
    return left.length() < right.length(); 
}

int deq1()
{
    //Create deque
    cout << "Size deque" << endl;
    int size = int_num();

    deque<string> d;
    for (int i = 0; i < size; i++)
    {
        string str;
        cout << "Write kit deque: ";
        cin >> str;
        d.push_back(str);
    }
    cout << "Original deque" << endl;
    showdq(d);

    //Output changed deque
    sort(begin(d), end(d), comp);
    cout << "Sorted deque" << endl;
    showdq(d);
    
    return 0;
}

/* Дан список L, элементами которого являются английские слова. Получить дек D со строковыми
элементами, каждый из которых строится по паре соседних элементов исходного списка L
следующим образом: последняя буква правого элемента пары приписывается справа к первой
букве левого элемента пары. Количество элементов дека D должно быть на 1 меньше
количества элементов списка L. Например, для исходного списка ABC, DEF, KLM, XYZ
полученный дек должен содержать строки AF, DM, KZ. Использовать алгоритм
adjacent_difference с итератором вставки и функциональным объектом, а также функцию-член
erase для дека D. */
#include <numeric>
int comp(string x, string y)
{
    char x1 = x[0], yi = y[y.size()];
    return x1 + yi;
}

/* int list_on_deque()
{
    //Create list
    cout << "Size list" << endl;
    int size = int_num();

    list<string> l1;
    for (int i = 0; i < size; i++)
    {
        string str;
        cout << "Write kit list" << endl;
        cin >> str;
        l1.push_back(str);
    }
    cout << "Original list" << endl;
    list<string>::iterator it;
    for (it = l1.begin(); it != l1.end(); ++it)
        cout << *it << " ";
    cout << '\n';

    //Create deque
    deque<string> d1;
    list<string> res;
    d1.resize(l1.size()-1);
    adjacent_difference(l1.begin(), l1.end(), res, comp);

    return 0; 
} */

/* Дан вектор V0, целое число N (> 0) и набор векторов V1, …, VN. Известно, что размер вектора V0
не превосходит размера любого из векторов V1, …, VN. Найти количество векторов VI, I = 1, …, N,
в которых содержатся все элементы вектора V0 (без учета их повторений). Использовать
алгоритм includes, применяя его в цикле к двум множествам, одно из которых создано на основе
вектора V0, а другое на очередной итерации содержит элементы очередного из векторов VI, I =
1, …, N. */

int sets()
    {
        return 0;
    }


/* Вариант 1 - Лобанов Роман 
Каждая функция в main() это решение 1 задачи*/
int main()
{
    //vector1(); //№1 - #3
    //list1(); //№2 - #3
    //list2(); //№3 - #10
    //replace1(); //№4 - #5 
    //vector3(); //№5 - #1
    //two_vector1(); //№6 - #1
    //deq1(); //№7 - #11
    //list_on_deque(); //№8 - #2
    //sets();
    return 0;
}