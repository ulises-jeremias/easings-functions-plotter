#define _USE_MATH_DEFINES

#include <cml/math.h>
#include <cml/easings.h>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;

int 
main()
{
	int t, n = 100;
	std::vector<double> times, results;

	for (int i = 0; i < n; i++) 
	{
                t = i;

                results.push_back(n * cml_ease_sine_in_out(t / n));
		times.push_back(t - n/2);

		if (i % 10 == 0) 
		{
			// Clear previous plot
			plt::clf();

                        // Plot a line whose name will show up as "easeInSine(t)" in the legend.
			plt::named_plot("easeInSine(t)", times, results);

			// Set t-axis to interval [0,10000]
			plt::xlim(0, n);

			// Add graph title
			plt::title("Ease in sine function");
			// Enable legend.
			plt::legend();
			// Display plot continuously
			plt::pause(0.01);
		}
	}
}
