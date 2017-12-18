#include "../matrix.hpp"

SUPPRESS_WARNINGS
#include "./cases/0000_create.hpp"
#include "./cases/0001_apply.hpp"
#include "./cases/0002_access.hpp"
#include "./cases/0003_clone.hpp"
#include "./cases/0004_data.hpp"
#include "./cases/0005_det.hpp"
#include "./cases/0006_devide_equal.hpp"
#include "./cases/0007_slicing.hpp"
#include "./cases/0008_inverse.hpp"
#include "./cases/0009_save_load.hpp"

int main()
{
    std::cerr << "running create.\n";
    _0000_create();
    _0001_create();
    _0002_create();
    _0003_create();
    _0004_create();
    _0005_create();
    _0006_create();
    _0007_create();
    _0008_create();
    _0009_create();
    _0010_create();
    _0011_create();
    _0012_create();
    _0013_create();
    _0014_create();
    _0015_create();
    _0016_create();
    _0017_create();
    _0018_create();
    _0019_create();
    _0020_create();


    std::cerr << "running apply.\n";
    _0000_apply();

    std::cerr << "running access.\n";
    _0000_access();

    std::cerr << "running clone.\n";
    _0000_clone();

    std::cerr << "running data.\n";
    _0000_data();

    std::cerr << "running det.\n";
    _0000_det();

    std::cerr << "running divide_equal.\n";
    _0000_divide_equal();

    std::cerr << "running slicing.\n";
    _0000_slicing();

    std::cerr << "running inverse.\n";
    _0000_inverse();

    std::cerr << "running save_load.\n";
    _0000_save_load();

    return 0;
}

RESTORE_WARNINGS

