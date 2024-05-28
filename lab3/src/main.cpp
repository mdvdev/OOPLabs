#include "MainWindow.h"

#include <QApplication>
#include <iostream>
#include <sstream>

#include "LongFloat.h"

void addTests()
{
    assert(std::string(LongFloat("15.53434343") + LongFloat("34.5")) == "50.034343");
    assert(std::string(LongFloat("15.534343") + LongFloat("34.5")) == "50.034343");
    assert(std::string(LongFloat("12345.678901") + LongFloat("0.000001")) == "12345.678902");
    assert(std::string(LongFloat("0.000001") + LongFloat("0.000001")) == "0.000002");
    assert(std::string(LongFloat("999999999999.999999") + LongFloat("0.000001")) == "1000000000000.0");
    assert(std::string(LongFloat("-123.456789") + LongFloat("123.456789")) == "0.0");
    assert(std::string(LongFloat("-0.000001") + LongFloat("0.000002")) == "0.000001");
    assert(std::string(LongFloat("0") + LongFloat("0")) == "0");
    assert(std::string(LongFloat("0.123456") + LongFloat("0.654321")) == "0.777777");
    assert(std::string(LongFloat("1.123456") + LongFloat("2.654321")) == "3.777777");
    assert(std::string(LongFloat("1000000000") + LongFloat("0")) == "1000000000");
    assert(std::string(LongFloat("478574385235723547834753245823") + LongFloat("343434343434343")) == "478574385235723891269096680166");
    assert(std::string(LongFloat("478574385235723547834753245823") + LongFloat("0.123456")) == "478574385235723547834753245823.123456");
    assert(std::string(LongFloat("999999999999999999") + LongFloat("1")) == "1000000000000000000");
    assert(std::string(LongFloat("0.999999") + LongFloat("0.000001")) == "1.0");
    assert(std::string(LongFloat("1000000.999999") + LongFloat("0.000001")) == "1000001.0");
    assert(std::string(LongFloat("123456789.123456") + LongFloat("987654321.654321")) == "1111111110.777777");
    assert(std::string(LongFloat("987654321987654321.123456") + LongFloat("123456789123456789.654321")) == "1111111111111111110.777777");
    assert(std::string(LongFloat("123456789123456789123456789") + LongFloat("987654321987654321987654321")) == "1111111111111111111111111110");
    assert(std::string(LongFloat("0") + LongFloat("999999999999999999999999999")) == "999999999999999999999999999");
    assert(std::string(LongFloat("0.000001") + LongFloat("999999999999999999999999999")) == "999999999999999999999999999.000001");
    assert(std::string(LongFloat("0.0000000000000000001") + LongFloat("999999999999999999999999999")) == "999999999999999999999999999.0");
    assert(std::string(LongFloat("-0") + LongFloat("-0")) == "0");
}

void subtractTests()
{
    assert(std::string(LongFloat("50.034343") - LongFloat("34.5")) == "15.534343");
    assert(std::string(LongFloat("12345.678902") - LongFloat("0.000001")) == "12345.678901");
    assert(std::string(LongFloat("0.000002") - LongFloat("0.000001")) == "0.000001");
    assert(std::string(LongFloat("1000000000000.0") - LongFloat("0.000001")) == "999999999999.999999");
    assert(std::string(LongFloat("123.456789") - LongFloat("123.456789")) == "0.0");
    assert(std::string(LongFloat("0.000001") - LongFloat("0.000002")) == "-0.000001");
    assert(std::string(LongFloat("0") - LongFloat("0")) == "0");
    assert(std::string(LongFloat("0.777777") - LongFloat("0.654321")) == "0.123456");
    assert(std::string(LongFloat("3.777777") - LongFloat("2.654321")) == "1.123456");
    assert(std::string(LongFloat("1000000000") - LongFloat("0")) == "1000000000");
    assert(std::string(LongFloat("478574385235723547834753245823") - LongFloat("343434343434343")) == "478574385235723204400409811480");
    assert(std::string(LongFloat("478574385235723547834753245823") - LongFloat("0.123456")) == "478574385235723547834753245822.876544");
    assert(std::string(LongFloat("999999999999999999") - LongFloat("1")) == "999999999999999998");
    assert(std::string(LongFloat("0.999999") - LongFloat("0.000001")) == "0.999998");
    assert(std::string(LongFloat("1000000.999999") - LongFloat("0.000001")) == "1000000.999998");
    assert(std::string(LongFloat("123456789.123456") - LongFloat("987654321.654321")) == "-864197532.530865");
    assert(std::string(LongFloat("987654321987654321.123456") - LongFloat("123456789123456789.654321")) == "864197532864197531.469135");
    assert(std::string(LongFloat("123456789123456789123456789") - LongFloat("987654321987654321987654321")) == "-864197532864197532864197532");
    assert(std::string(LongFloat("0") - LongFloat("999999999999999999999999999")) == "-999999999999999999999999999");
    assert(std::string(LongFloat("0.000001") - LongFloat("999999999999999999999999999")) == "-999999999999999999999999998.999999");
}

void multipTests()
{
    assert(std::string(LongFloat("15.534343") * LongFloat("34.5")) == "535.934833");
    assert(std::string(LongFloat("12345.678901") * LongFloat("0.000001")) == "0.012345");
    assert(std::string(LongFloat("0.000001") * LongFloat("0.000001")) == "0.0");
    assert(std::string(LongFloat("999999999999.999999") * LongFloat("0.000001")) == "999999.999999");
    assert(std::string(LongFloat("-123.456789") * LongFloat("123.456789")) == "-15241.57875");
    assert(std::string(LongFloat("-0.000001") * LongFloat("0.000002")) == "0.0");
    assert(std::string(LongFloat("0") * LongFloat("0")) == "0");
    assert(std::string(LongFloat("0.123456") * LongFloat("0.654321")) == "0.080779");
    assert(std::string(LongFloat("1.123456") * LongFloat("2.654321")) == "2.982012");
    assert(std::string(LongFloat("1000000000") * LongFloat("0")) == "0");
    assert(std::string(LongFloat("478574385235723547834753245823") * LongFloat("343434343434343")) == "164358879777925050986697426483529728339499289");
    assert(std::string(LongFloat("478574385235723547834753245823") * LongFloat("0.123456")) == "59082879303661486321487296716.324288");
    assert(std::string(LongFloat("999999999999999999") * LongFloat("1")) == "999999999999999999");
    assert(std::string(LongFloat("0.999999") * LongFloat("0.000001")) == "0.0");
    assert(std::string(LongFloat("1000000.999999") * LongFloat("0.000001")) == "1.0");
    assert(std::string(LongFloat("123456789.123456") * LongFloat("987654321.654321")) == "121932631315347490.569424");
    assert(std::string(LongFloat("987654321987654321.123456") * LongFloat("123456789123456789.654321")) == "121932631356500532008687614087944713.394604");
    assert(std::string(LongFloat("123456789123456789123456789") * LongFloat("987654321987654321987654321")) == "121932631356500531591068431581771069347203169112635269");
    assert(std::string(LongFloat("0") * LongFloat("999999999999999999999999999")) == "0");
    assert(std::string(LongFloat("0.000001") * LongFloat("999999999999999999999999999")) == "999999999999999999999.999999");
}

void divisionTests()
{
    assert(std::string(LongFloat("0") / LongFloat("999999999999999999999999999")) == "0");
    assert(std::string(LongFloat("100") / LongFloat("4")) == "25");
    assert(std::string(LongFloat("123456789") / LongFloat("3")) == "41152263");
    assert(std::string(LongFloat("1") / LongFloat("2")) == "0.5");
    assert(std::string(LongFloat("100") / LongFloat("0.5")) == "200");
    assert(std::string(LongFloat("123456789") / LongFloat("0.1")) == "1234567890");
    assert(std::string(LongFloat("100") / LongFloat("0.123456")) == "810.005184");
    assert(std::string(LongFloat("0.5") / LongFloat("0.2")) == "2.5");
    assert(std::string(LongFloat("0.123456") / LongFloat("0.123456")) == "1");
    assert(std::string(LongFloat("123.456") / LongFloat("0.1")) == "1234.56");
    assert(std::string(LongFloat("0") / LongFloat("123456789")) == "0");
    assert(std::string(LongFloat("1") / LongFloat("0.000001")) == "1000000");
    assert(std::string(LongFloat("0.000001") / LongFloat("1")) == "0.000001");
    assert(std::string(LongFloat("123456789123456789123456789") / LongFloat("3")) == "41152263041152263041152263");
    assert(std::string(LongFloat("999999999999999999999999999") / LongFloat("1")) == "999999999999999999999999999");
    assert(std::string(LongFloat("123456789123456789123456789") / LongFloat("123456789123456789")) == "1000000000.0");
    assert(std::string(LongFloat("987654321987654321987654321") / LongFloat("123456789123456789123456789")) == "8.0");
    assert(std::string(LongFloat("0.000001") / LongFloat("0.000001")) == "1");
    assert(std::string(LongFloat("0.0000001") / LongFloat("0.000001")) == "0");
    assert(std::string(LongFloat("-100") / LongFloat("2")) == "-50");
    assert(std::string(LongFloat("100") / LongFloat("-2")) == "-50");
    assert(std::string(LongFloat("-100") / LongFloat("-2")) == "50");
    assert(std::string(LongFloat("0.000001") / LongFloat("-1000000")) == "0.0");
    assert(std::string(LongFloat("-0.000001") / LongFloat("1000000")) == "0.0");
    assert(std::string(LongFloat("123456789.123456") / LongFloat("987654321.654321")) == "0.124999");
    assert(std::string(LongFloat("987654321.654321") / LongFloat("123456789.123456")) == "8.0");
    assert(std::string(LongFloat("1") / LongFloat("3")) == "0.333333");
    assert(std::string(LongFloat("22") / LongFloat("7")) == "3.142857");
    assert(std::string(LongFloat("0.123456") / LongFloat("1000000")) == "0.0");
    assert(std::string(LongFloat("4534535123453553452546545456346") / LongFloat("34344343")) == "132031500018898409340558.515163");
    assert(std::string(LongFloat("237847823487281482378472317472374743741727472374712374732172377417273") / LongFloat("4")) == "59461955871820370594618079368093685935431868093678093683043094354318.25");
    assert(std::string(LongFloat("4443545353453453452349934800342343") / LongFloat("23233034934")) == "191259788748073573242703.359004");
}

void runTests()
{
    addTests();

    subtractTests();

    multipTests();

    divisionTests();

    std::cout << "All tests passed!\n";
}

int main(int argc, char* argv[])
{
    runTests();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
