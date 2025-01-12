/// @ref ext2_float_bits_cast

namespace glm
{
	// Overload the GLM common functions (floatBitsToInt, floatBitsToUint, intBitsToFloat,
	// and uintBitsToFloat) for the double type.

	GLM_FUNC_QUALIFIER int64 floatBitsToInt(double v)
	{
		union
		{
			double in;
			int64 out;
		} u;

		u.in = v;

		return u.out;
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, int64, Q> floatBitsToInt(vec<L, double, Q> const& v)
	{
		return detail::functor1<vec, L, int64, double, Q>::call(floatBitsToInt, v);
	}

	GLM_FUNC_QUALIFIER uint64 floatBitsToUint(double v)
	{
		union
		{
			double in;
			uint64 out;
		} u;

		u.in = v;

		return u.out;
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, uint64, Q> floatBitsToUint(vec<L, double, Q> const& v)
	{
		return detail::functor1<vec, L, uint64, double, Q>::call(floatBitsToUint, v);
	}

	GLM_FUNC_QUALIFIER double intBitsToFloat(int64 v)
	{
		union
		{
			int64 in;
			double out;
		} u;

		u.in = v;

		return u.out;
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, double, Q> intBitsToFloat(vec<L, int64, Q> const& v)
	{
		return detail::functor1<vec, L, double, int64, Q>::call(intBitsToFloat, v);
	}

	GLM_FUNC_QUALIFIER double uintBitsToFloat(uint64 v)
	{
		union
		{
			uint64 in;
			double out;
		} u;

		u.in = v;

		return u.out;
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, double, Q> uintBitsToFloat(vec<L, uint64, Q> const& v)
	{
		return reinterpret_cast<vec<L, double, Q>&>(const_cast<vec<L, uint64, Q>&>(v));
	}

		
	GLM_FUNC_QUALIFIER uint float_as_bits(float v)
	{
#if defined(__CUDA_ARCH__)

		return (uint)__float_as_uint(v);

#elif defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER) || \
	  (defined(_MSC_VER) && (_MSC_VER >= 1932) || defined(__clang__) && (__clang_major__ >= 10)) && \
	  (defined(_M_IX86) || defined(_M_X64))
	
		return (uint)_castf32_u32(v);

#elif defined(_MSC_VER) && !defined(__clang__) && (defined(_M_ARM) || defined(_M_ARM64))

		return (uint)_CopyInt32FromFloat(v);

#else

		union
		{
			float in;
			uint  out;
		} u = { v };
	
		return u.out;

#endif
	}

	GLM_FUNC_QUALIFIER uint64 float_as_bits(double v)
	{
#if defined(__CUDA_ARCH__)

		return (uint64)__double_as_longlong(v);

#elif defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER) || \
	  (defined(_MSC_VER) && (_MSC_VER >= 1932) || defined(__clang__) && (__clang_major__ >= 10)) && \
	  (defined(_M_IX86) || defined(_M_X64))
	
		return (uint64)_castf64_u64(v);

#elif defined(_MSC_VER) && !defined(__clang__) && (defined(_M_ARM) || defined(_M_ARM64))

		return (uint64)_CopyInt64FromDouble(v);

#else

		union
		{
			double in;
			uint64 out;
		} u = { v };
	
		return u.out;

#endif
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, uint, Q> float_as_bits(vec<L, float, Q> const& v)
	{
		return detail::functor1<vec, L, uint, float, Q>::call(float_as_bits, v);
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, uint64, Q> float_as_bits(vec<L, double, Q> const& v)
	{
		return detail::functor1<vec, L, uint64, double, Q>::call(float_as_bits, v);
	}


	GLM_FUNC_QUALIFIER float bits_as_float(uint v)
	{
#if defined(__CUDA_ARCH__)

		return __uint_as_float((unsigned int)v);

#elif defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER) || \
	  (defined(_MSC_VER) && (_MSC_VER >= 1932) || defined(__clang__) && (__clang_major__ >= 10)) && \
	  (defined(_M_IX86) || defined(_M_X64))
	
		return _castu32_f32((unsigned __int32)v);

#elif defined(_MSC_VER) && !defined(__clang__) && (defined(_M_ARM) || defined(_M_ARM64))

		return _CopyFloatFromInt32((__int32)w);

#else

		union
		{
			uint  in;
			float out;
		} u = { v };
	
		return u.out;

#endif
	}

	GLM_FUNC_QUALIFIER double bits_as_float(uint64 v)
	{
#if defined(__CUDA_ARCH__)

		return __longlong_as_double((long long)v);

#elif defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER) || \
	  (defined(_MSC_VER) && (_MSC_VER >= 1932) || defined(__clang__) && (__clang_major__ >= 10)) && \
	  (defined(_M_IX86) || defined(_M_X64))
	
		return _castu64_f64((unsigned __int64)v);

#elif defined(_MSC_VER) && !defined(__clang__) && (defined(_M_ARM) || defined(_M_ARM64))

		return _CopyDoubleFromInt64((__int64)v);

#else

		union
		{
			uint64 in;
			double out;
		} u = { v };
	
		return u.out;

#endif
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, float, Q> bits_as_float(vec<L, uint, Q> const& v)
	{
		return reinterpret_cast<vec<L, float, Q>&>(const_cast<vec<L, uint, Q>&>(v));
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, double, Q> bits_as_float(vec<L, uint64, Q> const& v)
	{
		return reinterpret_cast<vec<L, double, Q>&>(const_cast<vec<L, uint64, Q>&>(v));
	}
}//namespace glm
