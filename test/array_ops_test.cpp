#include "laba1/array_ops.hpp"

#include <gtest/gtest.h>

namespace laba1 {
namespace {

TEST(ArrayOpsTest, Creation) {
    int* arr = array_create(5);

    ASSERT_NE(arr, nullptr);

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
    EXPECT_EQ(arr[3], 40);
    EXPECT_EQ(arr[4], 50);

    array_delete(arr);
}

TEST(ArrayOpsTest, Deletion) {
    int* arr = array_create(5);

    array_delete(arr);

    ASSERT_EQ(arr, nullptr);
}

TEST(ArrayOpsTest, ResizeGrow) {
    int* arr = array_create(5);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    arr = array_resize(arr, 5, 8);
    ASSERT_NE(arr, nullptr);

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
    EXPECT_EQ(arr[3], 40);
    EXPECT_EQ(arr[4], 50);

    array_delete(arr);
}

TEST(ArrayOpsTest, ResizingShrink) {
    int* arr = array_create(5);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    arr = array_resize(arr, 5, 3);
    ASSERT_NE(arr, nullptr);

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);

    array_delete(arr);
}

TEST(ArrayOpsTest, InsertMiddle) {
    int* arr = array_create(5);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    std::size_t size = 5;

    arr = array_insert(arr, size, 2, 99);

    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(size, 6);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 99);
    EXPECT_EQ(arr[3], 30);
    EXPECT_EQ(arr[4], 40);
    EXPECT_EQ(arr[5], 50);

    array_delete(arr);
}

TEST(ArrayOpsTest, InsertAtStart) {
    int* arr = array_create(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    std::size_t size = 3;

    arr = array_insert(arr, size, 0, 99);

    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(size, 4);
    EXPECT_EQ(arr[0], 99);
    EXPECT_EQ(arr[1], 10);
    EXPECT_EQ(arr[2], 20);
    EXPECT_EQ(arr[3], 30);

    array_delete(arr);
}

TEST(ArrayOpsTest, InsertAtEnd) {
    int* arr = array_create(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    std::size_t size = 3;

    arr = array_insert(arr, size, 3, 99);

    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(size, 4);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
    EXPECT_EQ(arr[3], 99);

    array_delete(arr);
}

TEST(ArrayOpsTest, RemoveMiddle) {
    int* arr = array_create(5);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    std::size_t size = 5;

    arr = array_remove(arr, size, 2);

    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(size, 4);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 40);
    EXPECT_EQ(arr[3], 50);

    array_delete(arr);
}

TEST(ArrayOpsTest, RemoveFirst) {
    int* arr = array_create(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    std::size_t size = 3;

    arr = array_remove(arr, size, 0);

    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(size, 2);
    EXPECT_EQ(arr[0], 20);
    EXPECT_EQ(arr[1], 30);

    array_delete(arr);
}

TEST(ArrayOpsTest, RemoveLast) {
    int* arr = array_create(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    std::size_t size = 3;

    arr = array_remove(arr, size, 2);

    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(size, 2);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);

    array_delete(arr);
}

TEST(ArrayOpsTest, RemoveOnlyElement) {
    int* arr = array_create(1);
    arr[0] = 42;
    std::size_t size = 1;

    arr = array_remove(arr, size, 0);

    EXPECT_EQ(size, 0);

    array_delete(arr);
}

TEST(ArrayOpsTest, MergeTwoSortedArrays) {
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    std::size_t out_size;

    int* merged = array_merge(a, 3, b, 3, out_size);

    ASSERT_NE(merged, nullptr);
    EXPECT_EQ(out_size, 6);
    EXPECT_EQ(merged[0], 1);
    EXPECT_EQ(merged[1], 2);
    EXPECT_EQ(merged[2], 3);
    EXPECT_EQ(merged[3], 4);
    EXPECT_EQ(merged[4], 5);
    EXPECT_EQ(merged[5], 6);

    array_delete(merged);
}

TEST(ArrayOpsTest, MergeWithEmptyArray) {
    int a[] = {1, 2, 3};
    std::size_t out_size;

    int* merged = array_merge(a, 3, nullptr, 0, out_size);

    ASSERT_NE(merged, nullptr);
    EXPECT_EQ(out_size, 3);
    EXPECT_EQ(merged[0], 1);
    EXPECT_EQ(merged[1], 2);
    EXPECT_EQ(merged[2], 3);

    array_delete(merged);
}

}
}