#include "HalideRuntime.h"
#include "HalideRuntimeCuda.h"
#include "HalideRuntimeOpenGL.h"
#include "HalideRuntimeOpenGLCompute.h"
#include "HalideRuntimeOpenCL.h"
#include "HalideRuntimeRenderscript.h"
#include "HalideRuntimeMetal.h"
#include "HalideRuntimeHexagonHost.h"
#include "HalideRuntimeQurt.h"

// This runtime module will contain extern declarations of the Halide
// API and the types it uses. It's useful for compiling modules that
// use the API without including a copy of it (e.g. JIT, NoRuntime).

// Can be generated via the following:
// cat src/runtime/runtime_internal.h src/runtime/HalideRuntime*.h | grep "^[^ ][^(]*halide_[^ ]*(" | grep -v '#define' | sed "s/[^(]*halide/halide/" | sed "s/(.*//" | sed "s/^h/    \(void *)\&h/" | sed "s/$/,/" | sort | uniq

namespace {
__attribute__((used)) void *runtime_api_functions[] = {
    (void *)&halide_copy_to_device,
    (void *)&halide_copy_to_host,
    (void *)&halide_cuda_detach_device_ptr,
    (void *)&halide_cuda_device_interface,
    (void *)&halide_cuda_get_device_ptr,
    (void *)&halide_cuda_initialize_kernels,
    (void *)&halide_cuda_run,
    (void *)&halide_cuda_wrap_device_ptr,
    (void *)&halide_current_time_ns,
    (void *)&halide_debug_to_file,
    (void *)&halide_device_free,
    (void *)&halide_device_free_as_destructor,
    (void *)&halide_device_malloc,
    (void *)&halide_device_release,
    (void *)&halide_device_sync,
    (void *)&halide_do_par_for,
    (void *)&halide_double_to_string,
    (void *)&halide_enumerate_registered_filters,
    (void *)&halide_error,
    (void *)&halide_error_access_out_of_bounds,
    (void *)&halide_error_bad_elem_size,
    (void *)&halide_error_bounds_inference_call_failed,
    (void *)&halide_error_buffer_allocation_too_large,
    (void *)&halide_error_buffer_argument_is_null,
    (void *)&halide_error_buffer_extents_too_large,
    (void *)&halide_error_constraint_violated,
    (void *)&halide_error_constraints_make_required_region_smaller,
    (void *)&halide_error_debug_to_file_failed,
    (void *)&halide_error_explicit_bounds_too_small,
    (void *)&halide_error_extern_stage_failed,
    (void *)&halide_error_out_of_memory,
    (void *)&halide_error_param_too_large_f64,
    (void *)&halide_error_param_too_large_i64,
    (void *)&halide_error_param_too_large_u64,
    (void *)&halide_error_param_too_small_f64,
    (void *)&halide_error_param_too_small_i64,
    (void *)&halide_error_param_too_small_u64,
    (void *)&halide_float16_bits_to_double,
    (void *)&halide_float16_bits_to_float,
    (void *)&halide_free,
    (void *)&halide_get_gpu_device,
    (void *)&halide_get_library_symbol,
    (void *)&halide_get_symbol,
    (void *)&halide_get_trace_file,
    (void *)&halide_hexagon_detach_device_handle,
    (void *)&halide_hexagon_device_interface,
    (void *)&halide_hexagon_get_device_handle,
    (void *)&halide_hexagon_wrap_device_handle,
    (void *)&halide_hexagon_initialize_kernels,
    (void *)&halide_hexagon_run,
    (void *)&halide_hexagon_device_release,
    (void *)&halide_qurt_hvx_lock,
    (void *)&halide_qurt_hvx_unlock,
    (void *)&halide_qurt_hvx_unlock_as_destructor,
    (void *)&halide_int64_to_string,
    (void *)&halide_load_library,
    (void *)&halide_malloc,
    (void *)&halide_matlab_call_pipeline,
    (void *)&halide_memoization_cache_cleanup,
    (void *)&halide_memoization_cache_lookup,
    (void *)&halide_memoization_cache_release,
    (void *)&halide_memoization_cache_set_size,
    (void *)&halide_memoization_cache_store,
    (void *)&halide_metal_acquire_context,
    (void *)&halide_metal_detach_buffer,
    (void *)&halide_metal_device_interface,
    (void *)&halide_metal_get_buffer,
    (void *)&halide_metal_initialize_kernels,
    (void *)&halide_metal_release_context,
    (void *)&halide_metal_run,
    (void *)&halide_metal_wrap_buffer,
    (void *)&halide_mutex_cleanup,
    (void *)&halide_mutex_lock,
    (void *)&halide_mutex_unlock,
    (void *)&halide_opencl_detach_cl_mem,
    (void *)&halide_opencl_device_interface,
    (void *)&halide_opencl_get_cl_mem,
    (void *)&halide_opencl_get_device_type,
    (void *)&halide_opencl_get_platform_name,
    (void *)&halide_opencl_initialize_kernels,
    (void *)&halide_opencl_run,
    (void *)&halide_opencl_set_device_type,
    (void *)&halide_opencl_set_platform_name,
    (void *)&halide_opencl_wrap_cl_mem,
    (void *)&halide_opengl_context_lost,
    (void *)&halide_opengl_create_context,
    (void *)&halide_opengl_detach_texture,
    (void *)&halide_opengl_device_interface,
    (void *)&halide_opengl_get_proc_address,
    (void *)&halide_opengl_get_texture,
    (void *)&halide_opengl_initialize_kernels,
    (void *)&halide_opengl_run,
    (void *)&halide_opengl_wrap_render_target,
    (void *)&halide_opengl_wrap_texture,
    (void *)&halide_openglcompute_device_interface,
    (void *)&halide_openglcompute_initialize_kernels,
    (void *)&halide_openglcompute_run,
    (void *)&halide_pointer_to_string,
    (void *)&halide_print,
    (void *)&halide_profiler_get_state,
    (void *)&halide_profiler_get_pipeline_state,
    (void *)&halide_profiler_memory_allocate,
    (void *)&halide_profiler_memory_free,
    (void *)&halide_profiler_pipeline_start,
    (void *)&halide_profiler_report,
    (void *)&halide_profiler_reset,
    (void *)&halide_profiler_stack_peak_update,
    (void *)&halide_release_jit_module,
    (void *)&halide_renderscript_device_interface,
    (void *)&halide_renderscript_initialize_kernels,
    (void *)&halide_renderscript_run,
    (void *)&halide_runtime_internal_register_metadata,
    (void *)&halide_set_gpu_device,
    (void *)&halide_set_num_threads,
    (void *)&halide_set_trace_file,
    (void *)&halide_shutdown_thread_pool,
    (void *)&halide_shutdown_trace,
    (void *)&halide_sleep_ms,
    (void *)&halide_spawn_thread,
    (void *)&halide_start_clock,
    (void *)&halide_string_to_string,
    (void *)&halide_trace,
    (void *)&halide_uint64_to_string,
    (void *)&halide_use_jit_module,
};
}
