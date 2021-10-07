#pragma once
#ifndef __SORT_H__

#define __SORT_H__

// �迭 ���� ����� �Լ�

void printArr(int arr[], int n);

void genRandom(int arr[], int n, int bound);  // ������ �迭 0 ~ bound ������ ���� x n �� 

void genIncSorted(int arr[], int n); // ���� ���� �迭 

// ���� �Լ� �ð�üũ

typedef void fnSort(int arr[], int n);

void chkTimeLap(fnSort sort, int arr[], int n, char* title);

// ����(Sort) �Լ�

void BubbleSort(int arr[], int n);  // ��������

void SelectionSort(int arr[], int n);  // ��������

void InsertionSort(int arr[], int n);  // ��������


#endif