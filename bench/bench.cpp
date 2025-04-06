#include <benchmark/benchmark.h>
#include <he2paleo.h>

static void BM_scalar_unchecked(benchmark::State &state) {
	for (auto _ : state) {
		uint32_t c = 0x05DE;
		benchmark::ClobberMemory();
		benchmark::DoNotOptimize(
			he2paleo_scalar_unchecked(c)
		);
	}
}
BENCHMARK(BM_scalar_unchecked);