#pragma once

#include <iostream>
#include <atomic>
#include <thread>
#include <assert.h>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x()
{
	x.store(true);
}

void write_y()
{
	y.store(true);
}

void read_x_then_y()
{
	while (!x.load());
	if (y.load())
		++z;
}

void read_y_then_x()
{
	while (!y.load());
	if (x.load())
		++z;
}

int main()
{
	x = false;
	y = false;
	z = 0;
	std::thread a(write_x);
	std::thread b(write_y);
	std::thread c(read_x_then_y);
	std::thread d(read_y_then_x);

	a.join();
	b.join();
	c.join();
	d.join();

	std::cout << "z = " << z << std::endl;

	assert(z.load() != 0);
}