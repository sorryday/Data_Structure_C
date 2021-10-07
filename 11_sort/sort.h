#pragma once
#ifndef __SORT_H__

#define __SORT_H__

// 배열 관련 도우미 함수

void printArr(int arr[], int n);

void genRandom(int arr[], int n, int bound);  // 무작위 배열 0 ~ bound 범위의 숫자 x n 개 

void genIncSorted(int arr[], int n); // 오름 차순 배열 

// 정렬 함수 시간체크

typedef void fnSort(int arr[], int n);

void chkTimeLap(fnSort sort, int arr[], int n, char* title);

// 정렬(Sort) 함수

void BubbleSort(int arr[], int n);  // 버블정렬

void SelectionSort(int arr[], int n);  // 선택정렬

void InsertionSort(int arr[], int n);  // 삽입정렬


#endif