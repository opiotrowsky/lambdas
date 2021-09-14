#include <chrono>
#include <thread>
#include <string>
#include <functional>

/*  Napisz funkcję schedule(), która przyjmuje dwa parametry:
    Pierwszy parametr to dowolną funkcję func, która nie przyjmuje żadnego argumentu i nic nie zwraca
    Drugi parametr to okres czasu duration wyrażony w sekundach (użyj biblioteki std::chrono) Funkcja schedule()
    ma odczekać podany okres czasu duration, a potem wywołać funkcję func. */
void schedule(std::function<void()> func, std::chrono::seconds duration) {
    std::this_thread::sleep_for(duration);
    func();
}

/*  Napisz również przeciążenie funkcji schedule(), które oprócz okresu czasu ma przyjąć dowolną funkcję,
    która przyjmuje int i nic nie zwraca. Pomyśl jak przekazać ten argument int do tej funkcji. */
void schedule(std::function<void(int)> func, std::chrono::seconds duration, int number) {
    std::this_thread::sleep_for(duration);
    func(number);
}

/*  Napisz kolejne przeciążenie, które będzie przyjmować funkcje, które przyjmują std::string oraz double
    jako swoje argumenty i nic nie zwracają. */
void schedule(std::function<void(std::string, double)> func, std::chrono::seconds duration, std::string text, double value) {
    std::this_thread::sleep_for(duration);
    func(text, value);
}

/*  Bonus: zaimplementuj schedule jako funkcję szablonową. Wystarczy wtedy tylko jedna jej wersja, bez żadnych przeciążeń. */
template<typename T, typename... V>
void schedule(T func, std::chrono::seconds duration, V... values) {
    std::this_thread::sleep_for(duration);
    func(values...);
}