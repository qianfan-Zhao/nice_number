/*
 * ABOUT MORE: SEE
 * http://stackoverflow.com/questions/8506881/nice-label-algorithm-for-charts-with-minimum-ticks
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
 * Returns a "nice" number approximately equal to range Rounds
 * the number if round = true Takes the ceiling if round = false.
 *
 * @range: the data range
 * @is_round: whether to round the result
 * @reture: a "nice" number to be used for the data range
 */
double _nice_num(double range, int is_round) {
	double exponent; /** exponent of range */
	double fraction; /** fractional part of range */
	double niceFraction; /** nice, rounded fraction */

	exponent = floor(log10(range));
	fraction = range / pow(10, exponent);

	if (is_round) {
	  if (fraction < 1.5)
		niceFraction = 1;
	  else if (fraction < 3)
		niceFraction = 2;
	  else if (fraction < 7)
		niceFraction = 5;
	  else
		niceFraction = 10;
	} else {
	  if (fraction < 1)
		niceFraction = 1;
	  else if (fraction < 2)
		niceFraction = 2;
	  else if (fraction < 5)
		niceFraction = 5;
	  else
		niceFraction = 10;
	}

	return niceFraction * pow(10, exponent);
}

/*
 * Calculate and return values for tick spacing.
 *  @minp: the minimum data point on the axis
 *  @maxp: the maximum data point on the axis
 *  @max_ticks: the maximum number of tick marks for the axis
 */
double nice_number(double minp, double maxp, int max_ticks,
	double *nice_min, double *nice_max)
{
	double range, tick_spacing;

	assert(max_ticks > 1);
	range = _nice_num(maxp - minp, 0);
	tick_spacing = _nice_num(range / (max_ticks - 1), 1);

	if(nice_min) *nice_min = floor(minp / tick_spacing) * tick_spacing;
	if(nice_max) *nice_max = ceil(maxp / tick_spacing) * tick_spacing;

	return tick_spacing;
}

int main(int argc, char *argv[])
{
	int max_ticks;
	double minp, maxp, step;
	double nice_min, nice_max, nice_num;

	if(argc != 4) {
		fprintf(stderr, "Usage: %s min_point max_point max_ticks\n"
						"@min_point: the minimum data point on the axis\n"
						"@max_point: the maximum data point on the axis\n"
						"max_ticks: the maximum number of tick marks for the axis\n", argv[0]);
		exit(-1);
	}

	minp = strtod(argv[1], NULL);
	maxp = strtod(argv[2], NULL);
	max_ticks = (int)strtol(argv[3], NULL, 10);

	nice_num = nice_number(minp, maxp, max_ticks, &nice_min, &nice_max);
	printf("num: %lf, min: %lf, max: %lf\n", nice_num, nice_min, nice_max);
	for(step = nice_min; step <= nice_max; step += nice_num)
		printf("%lf | ", step);
	printf("\n");

	return 0;
}
