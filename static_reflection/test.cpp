#include "serialize.hpp"

// ------------------------------------------------------------
// Test types
// ------------------------------------------------------------

struct Point {
    int x;
    int y;
};


struct Sensor {
    int id;
    float value;
};


struct TestData {
    int number;

    char name[16];

    int values[4];

    float matrix[2][3];

    Point position;

    Sensor sensors[2];
};


// ------------------------------------------------------------
// main
// ------------------------------------------------------------

int main()
{
    // buffer は現状使わないので nullptr でよい
    // binser_buffer_t* buffer = nullptr;


    std::cout << "===== scalar =====\n";

    int value = 42;
    serialize(value, 0);


    std::cout << "\n===== char array =====\n";

    char name[] = "hello";
    serialize(name, 0);


    std::cout << "\n===== int array =====\n";

    int values[] = {1, 2, 3, 4, 5};
    serialize(values, 0);


    std::cout << "\n===== float array =====\n";

    float floats[] = {
        1.1f,
        2.2f,
        3.3f
    };

    serialize(floats, 0);


    std::cout << "\n===== 2D array =====\n";

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    serialize(matrix, 0);


    std::cout << "\n===== struct =====\n";

    Point point{
        .x = 10,
        .y = 20
    };

    serialize(point, 0);


    std::cout << "\n===== struct array =====\n";

    Sensor sensors[] = {
        {
            .id = 1,
            .value = 12.5f
        },
        {
            .id = 2,
            .value = 34.5f
        }
    };

    serialize(sensors, 0);


    std::cout << "\n===== nested struct =====\n";

    TestData data{
        .number = 123,

        .name = "test",

        .values = {
            10, 20, 30, 40
        },

        .matrix = {
            {1, 2, 3},
            {4, 5, 6}
        },

        .position = {
            .x = 100,
            .y = 200
        },

        .sensors = {
            {
                .id = 1,
                .value = 1.5f
            },
            {
                .id = 2,
                .value = 2.5f
            }
        }
    };

    serialize(data, 0);
}