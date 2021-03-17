//---------------------------------------------------------------------------

#ifndef JanelaH
#define JanelaH
//---------------------------------------------------------------------------
class Janela
{
	public:
		double Xmin;
		double Xmax;
		double Ymin;
		double Ymax;

		Janela(double, double, double, double);
		void EditarX(double, double);
		void EditarY(double, double);
		void IncrementarX(double, double);
		void IncrementarY(double, double);
};
#endif
