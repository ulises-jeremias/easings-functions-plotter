#define _USE_MATH_DEFINES

#include <cml/math.h>
#include <cml/easings.h>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;

int 
main()
{
	int t, n = 1000;
	std::vector<double> results, times;

	for (int i = 0; i < n; i++) 
	{
                t = i * i;

                results.push_back(cml_linear_interpolation(t));
		times.push_back(t);

		if (i % 10 == 0) 
		{
			// Clear previous plot
			plt::clf();
			// Plot line from given t and x data. Color is selected automatically.
			plt::plot(times, results);
                        // Plot a line whose name will show up as "linear(t)" in the legend.
			plt::named_plot("linear(t)", times, results);

			// Set t-axis to interval [0,1000000]
			plt::xlim(0, n * n);

			// Add graph title
			plt::title("Linear function");
			// Enable legend.
			plt::legend();
			// Display plot continuously
			plt::pause(0.01);
		}
	}
}
