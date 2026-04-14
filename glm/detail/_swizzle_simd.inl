/// @ref core
/// @file glm/detail/_swizzle_simd.inl

#if GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR
	template<length_t L, qualifier Q, int E0, int E1, int E2, int E3>
	struct _swizzle_base1<L, float, Q, E0,E1,E2,E3, true> : public _swizzle_base0<float, L>
	{
		GLM_FUNC_QUALIFIER vec<L, float, Q> operator ()()  const
		{
			__m128 data = *reinterpret_cast<__m128 const*>(&this->_buffer);

			vec<L, float, Q> Result;
#			if GLM_ARCH & GLM_ARCH_AVX_BIT
				Result.data = _mm_permute_ps(data, _MM_SHUFFLE(E3, E2, E1, E0));
#			else
				Result.data = _mm_shuffle_ps(data, data, _MM_SHUFFLE(E3, E2, E1, E0));
#			endif
			return Result;
		}
	};

	template<qualifier Q, int E0, int E1, int E2, int E3>
	struct _swizzle_base1<2, float, Q, E0, E1, E2, E3, true> : public _swizzle_base1<2, float, Q, E0, E1, E2, E3, false> {};

	template<qualifier Q, int E0, int E1, int E2, int E3>
	struct _swizzle_base1<2, int, Q, E0, E1, E2, E3, true> : public _swizzle_base1<2, int, Q, E0, E1, E2, E3, false> {};

	template<length_t L, qualifier Q, int E0, int E1, int E2, int E3>
	struct _swizzle_base1<L, int, Q, E0,E1,E2,E3, true> : public _swizzle_base0<int, L>
	{
		GLM_FUNC_QUALIFIER vec<L, int, Q> operator ()()  const
		{
			__m128i data = *reinterpret_cast<__m128i const*>(&this->_buffer);

			vec<L, int, Q> Result;
			Result.data = _mm_shuffle_epi32(data, _MM_SHUFFLE(E3, E2, E1, E0));
			return Result;
		}
	};

	template<length_t L, qualifier Q, int E0, int E1, int E2, int E3>
	struct _swizzle_base1<L, uint, Q, E0,E1,E2,E3, true> : public _swizzle_base0<uint, L>
	{
		GLM_FUNC_QUALIFIER vec<L, uint, Q> operator ()()  const
		{
			__m128i data = *reinterpret_cast<__m128i const*>(&this->_buffer);

			vec<L, uint, Q> Result;
			Result.data = _mm_shuffle_epi32(data, _MM_SHUFFLE(E3, E2, E1, E0));
			return Result;
		}
	};
#endif// GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR
