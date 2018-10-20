#define _USE_MATH_DEFINES

#include <cml/math.h>
#include <cml/easings.h>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;

int 
main()
{
	int n = 1000;
	std::vector<double> times, results;

	for (int i = 0; i < n; i++) 
	{
                results.push_back(n * cml_ease_sine_in_out(2*M_PI*i/360.0));
		times.push_back(i*i);

		if (i % 10 == 0) 
		{
			// Clear previous plot
			plt::clf();

                        // Plot a line whose name will show up as "easeInOutSine(t)" in the legend.
			plt::named_plot("easeInOutSine(t)", times, results);

			// Set t-axis to interval [0,100000]
			plt::xlim(0, n*n);

			// Add graph title
			plt::title("Ease in out sine function");
			// Enable legend.
			plt::legend();
			// Display plot continuously
			plt::pause(0.01);
		}
	}
}
