#pragma once

//Ÿ�� �Ķ���Ϳ� typename�� class�� �ϴ� ���� �����ϴ�.
//���ڰ����� Ÿ���� �����ϸ� �˴ϴ�.
//������ typename�� Ÿ���� class�� Ŭ������ �����϶�� �˷��ִ� ������� ����մϴ�.
//intó�� ��Ȯ�� Ÿ���� ����� ��� Ÿ�Կ� �´� ���� �������ָ� �˴ϴ�.

template<int A, int B>
struct GCD
{
	static const int result = GCD<B, A % B>::result;
};

//���ø� Ư��ȭ�Դϴ�.
template<int A>
//GCD<>�� �ԷµǴ� B���� 0�ϰ�� �ش� 
//�ؿ������� �����ͼ� false�� ���ö����� �۵��ϴ��� Ȯ������
struct GCD<A, 0>
{
	static const int result = A;
};

void Metaprograming();