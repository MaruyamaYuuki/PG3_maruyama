#include <stdio.h>
#include <iostream>

template <typename Type, typename Type2>
class TemplateClass
{
public:
	TemplateClass(Type number1, Type2 number2) : Number1(number1),Number2(number2){}

	Type Min() {
		if (Number1 < Number2) {
			return static_cast<Type>(Number1);
		}
		else {
			return static_cast<Type2>(Number2);
		}
	}
private:
	Type Number1;
	Type2 Number2;
};

int main() {

	TemplateClass<int, float>intFloatTemplate(10, 50.0f);
	TemplateClass<int, double>intDoubleTemplate(80, 13.0);
	TemplateClass<float, int>floatIntTemplate(2.0f, 9);
	TemplateClass<float, double>floatDoubleTemplate(11.0f, 3.5);
	TemplateClass<double, int>doubleIntTemplate(666.0, 333);
	TemplateClass<double, float>doubleFloatTemplate(435.8, 563.5f);

	// printfでの表示
	printf("intとfoatを比べて小さい方を返す : %d\n", intFloatTemplate.Min());
	printf("intとdoubleを比べて小さい方を返す : %.d\n", intDoubleTemplate.Min());
	printf("floatとintを比べて小さい方を返す : %.2f\n", floatIntTemplate.Min());
	printf("floatとdoubleを比べて小さい方を返す : %.2f\n", floatDoubleTemplate.Min());
	printf("doubleとintを比べて小さい方を返す : %.2f\n", doubleIntTemplate.Min());
	printf("doubleとfloatを比べて小さい方を返す : %.2f\n\n", doubleFloatTemplate.Min());

	// std::coutでの表示
	std::cout << "intとfoatを比べて小さい方を返す : " << intFloatTemplate.Min() << std::endl;
	std::cout << "intとdoubleを比べて小さい方を返す : " << intDoubleTemplate.Min() << std::endl;
	std::cout << "floatとintを比べて小さい方を返す : " << floatIntTemplate.Min() << std::endl;
	std::cout << "floatとdoubleを比べて小さい方を返す : " << floatDoubleTemplate.Min() << std::endl;
	std::cout << "doubleとintを比べて小さい方を返す : " << doubleIntTemplate.Min() << std::endl;
	std::cout << "doubleとfloatを比べて小さい方を返す : " << doubleFloatTemplate.Min() << std::endl;

	return 0;
}