
#ifndef GENFGLTEST_H
#define GENFGLTEST_H

//#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/extensions/HelperMacros.h>
#include "FglParse.h"

class GenFglTest : public CppUnit::TestFixture
{
public:
  static CppUnit::Test *suite()
  {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite(
      "GenFglTest" 
    );

    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_10_ui_contrl",
      &GenFglTest::fgl_build_tests_10_ui_contrl ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_100_rep",
      &GenFglTest::fgl_build_tests_100_rep ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_101_prog",
      &GenFglTest::fgl_build_tests_101_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_11_scr",
      &GenFglTest::fgl_build_tests_11_scr ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_12_dec_round",
      &GenFglTest::fgl_build_tests_12_dec_round ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_12_dec_round2",
      &GenFglTest::fgl_build_tests_12_dec_round2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_12_dec_round3",
      &GenFglTest::fgl_build_tests_12_dec_round3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_12_dec_round4",
      &GenFglTest::fgl_build_tests_12_dec_round4 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_12_dec_round5",
      &GenFglTest::fgl_build_tests_12_dec_round5 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_12_dec_round6",
      &GenFglTest::fgl_build_tests_12_dec_round6 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_13_expr",
      &GenFglTest::fgl_build_tests_13_expr ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_14_rep",
      &GenFglTest::fgl_build_tests_14_rep ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_15_prompt",
      &GenFglTest::fgl_build_tests_15_prompt ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_202_m1",
      &GenFglTest::fgl_build_tests_202_m1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_202_m2",
      &GenFglTest::fgl_build_tests_202_m2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_203_m1",
      &GenFglTest::fgl_build_tests_203_m1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_204_m1",
      &GenFglTest::fgl_build_tests_204_m1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_205_m2",
      &GenFglTest::fgl_build_tests_205_m2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_206_select",
      &GenFglTest::fgl_build_tests_206_select ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_207_prog",
      &GenFglTest::fgl_build_tests_207_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_208_prog",
      &GenFglTest::fgl_build_tests_208_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_209_prog",
      &GenFglTest::fgl_build_tests_209_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_21_rep",
      &GenFglTest::fgl_build_tests_21_rep ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_210_prog",
      &GenFglTest::fgl_build_tests_210_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_211_prog",
      &GenFglTest::fgl_build_tests_211_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_212_prog",
      &GenFglTest::fgl_build_tests_212_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_212_prelude",
      &GenFglTest::fgl_build_tests_212_prelude ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_213_prog",
      &GenFglTest::fgl_build_tests_213_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_214_prog",
      &GenFglTest::fgl_build_tests_214_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_22_arr3",
      &GenFglTest::fgl_build_tests_22_arr3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_23_p1",
      &GenFglTest::fgl_build_tests_23_p1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_24_ibt",
      &GenFglTest::fgl_build_tests_24_ibt ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_25_xrpt",
      &GenFglTest::fgl_build_tests_25_xrpt ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_26_arr3a",
      &GenFglTest::fgl_build_tests_26_arr3a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_27_arr3b",
      &GenFglTest::fgl_build_tests_27_arr3b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_28_dt",
      &GenFglTest::fgl_build_tests_28_dt ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_29_disp",
      &GenFglTest::fgl_build_tests_29_disp ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_3_menu1",
      &GenFglTest::fgl_build_tests_3_menu1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_30_arr12",
      &GenFglTest::fgl_build_tests_30_arr12 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_30_inp",
      &GenFglTest::fgl_build_tests_30_inp ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_31_m1",
      &GenFglTest::fgl_build_tests_31_m1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_32_g2",
      &GenFglTest::fgl_build_tests_32_g2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_33_g1",
      &GenFglTest::fgl_build_tests_33_g1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_34_g1",
      &GenFglTest::fgl_build_tests_34_g1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_35_arith",
      &GenFglTest::fgl_build_tests_35_arith ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_36_temp",
      &GenFglTest::fgl_build_tests_36_temp ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_37_prompt",
      &GenFglTest::fgl_build_tests_37_prompt ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_38_arr3b",
      &GenFglTest::fgl_build_tests_38_arr3b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_39_zero",
      &GenFglTest::fgl_build_tests_39_zero ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_4_prompt_err",
      &GenFglTest::fgl_build_tests_4_prompt_err ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_40_test_257",
      &GenFglTest::fgl_build_tests_40_test_257 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_41_test_267",
      &GenFglTest::fgl_build_tests_41_test_267 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_42_test_265",
      &GenFglTest::fgl_build_tests_42_test_265 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_47_testdt_null",
      &GenFglTest::fgl_build_tests_47_testdt_null ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_48_rep",
      &GenFglTest::fgl_build_tests_48_rep ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_49_t1",
      &GenFglTest::fgl_build_tests_49_t1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_49_t2",
      &GenFglTest::fgl_build_tests_49_t2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_49_testdt",
      &GenFglTest::fgl_build_tests_49_testdt ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_50_using",
      &GenFglTest::fgl_build_tests_50_using ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_51_rep",
      &GenFglTest::fgl_build_tests_51_rep ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_51_x",
      &GenFglTest::fgl_build_tests_51_x ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_52_like",
      &GenFglTest::fgl_build_tests_52_like ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_53_m",
      &GenFglTest::fgl_build_tests_53_m ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_54_w",
      &GenFglTest::fgl_build_tests_54_w ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_56_k",
      &GenFglTest::fgl_build_tests_56_k ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_57_ia",
      &GenFglTest::fgl_build_tests_57_ia ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_58_m1",
      &GenFglTest::fgl_build_tests_58_m1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_59_m",
      &GenFglTest::fgl_build_tests_59_m ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_6_fgldrawbox",
      &GenFglTest::fgl_build_tests_6_fgldrawbox ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_60_m1",
      &GenFglTest::fgl_build_tests_60_m1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_61_match",
      &GenFglTest::fgl_build_tests_61_match ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_62_decassign",
      &GenFglTest::fgl_build_tests_62_decassign ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_62_t1",
      &GenFglTest::fgl_build_tests_62_t1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_63_constru",
      &GenFglTest::fgl_build_tests_63_constru ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_64_rg",
      &GenFglTest::fgl_build_tests_64_rg ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_66_decdiv",
      &GenFglTest::fgl_build_tests_66_decdiv ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_66_t1",
      &GenFglTest::fgl_build_tests_66_t1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_67_fgldb",
      &GenFglTest::fgl_build_tests_67_fgldb ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_68_dtblank",
      &GenFglTest::fgl_build_tests_68_dtblank ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_69_dt",
      &GenFglTest::fgl_build_tests_69_dt ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_70_arr3a",
      &GenFglTest::fgl_build_tests_70_arr3a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_71_r1",
      &GenFglTest::fgl_build_tests_71_r1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_72_r1",
      &GenFglTest::fgl_build_tests_72_r1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_72_r2",
      &GenFglTest::fgl_build_tests_72_r2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_73_into",
      &GenFglTest::fgl_build_tests_73_into ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_74_v",
      &GenFglTest::fgl_build_tests_74_v ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_75_r1",
      &GenFglTest::fgl_build_tests_75_r1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_76_datetime",
      &GenFglTest::fgl_build_tests_76_datetime ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_77_getfld",
      &GenFglTest::fgl_build_tests_77_getfld ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_78_moneytype",
      &GenFglTest::fgl_build_tests_78_moneytype ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_79_w",
      &GenFglTest::fgl_build_tests_79_w ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_8_error",
      &GenFglTest::fgl_build_tests_8_error ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_80_t",
      &GenFglTest::fgl_build_tests_80_t ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_82_rg2",
      &GenFglTest::fgl_build_tests_82_rg2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_84_chartst",
      &GenFglTest::fgl_build_tests_84_chartst ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_86_g1",
      &GenFglTest::fgl_build_tests_86_g1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_9_g1",
      &GenFglTest::fgl_build_tests_9_g1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_9_m1",
      &GenFglTest::fgl_build_tests_9_m1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_90_using",
      &GenFglTest::fgl_build_tests_90_using ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_91_put",
      &GenFglTest::fgl_build_tests_91_put ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_92_test_271",
      &GenFglTest::fgl_build_tests_92_test_271 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_93_rg1",
      &GenFglTest::fgl_build_tests_93_rg1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_94_desc",
      &GenFglTest::fgl_build_tests_94_desc ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_95_m1",
      &GenFglTest::fgl_build_tests_95_m1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_96_m1",
      &GenFglTest::fgl_build_tests_96_m1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_97_testna",
      &GenFglTest::fgl_build_tests_97_testna ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_98_testna",
      &GenFglTest::fgl_build_tests_98_testna ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_99_in",
      &GenFglTest::fgl_build_tests_99_in ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_99_in_db",
      &GenFglTest::fgl_build_tests_99_in_db ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_template_prog",
      &GenFglTest::fgl_build_tests_template_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_1_simple_null",
      &GenFglTest::fgl_build_tests_1_simple_null ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_215_prog",
      &GenFglTest::fgl_build_tests_215_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_216_prog",
      &GenFglTest::fgl_build_tests_216_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_217_prog",
      &GenFglTest::fgl_build_tests_217_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_217_prog2",
      &GenFglTest::fgl_build_tests_217_prog2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_218_rpc_client",
      &GenFglTest::fgl_build_tests_218_rpc_client ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_218_rpc_server",
      &GenFglTest::fgl_build_tests_218_rpc_server ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_219_prog",
      &GenFglTest::fgl_build_tests_219_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_220_prog",
      &GenFglTest::fgl_build_tests_220_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_221_prog",
      &GenFglTest::fgl_build_tests_221_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_222_prog",
      &GenFglTest::fgl_build_tests_222_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_223_prog",
      &GenFglTest::fgl_build_tests_223_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_224_prog",
      &GenFglTest::fgl_build_tests_224_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_225_prog",
      &GenFglTest::fgl_build_tests_225_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_226_prog",
      &GenFglTest::fgl_build_tests_226_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_227_prog",
      &GenFglTest::fgl_build_tests_227_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_228_prog",
      &GenFglTest::fgl_build_tests_228_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_229_prog",
      &GenFglTest::fgl_build_tests_229_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_230_prog",
      &GenFglTest::fgl_build_tests_230_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_231_prog",
      &GenFglTest::fgl_build_tests_231_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_232_prog",
      &GenFglTest::fgl_build_tests_232_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_233_prog",
      &GenFglTest::fgl_build_tests_233_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_234_prog",
      &GenFglTest::fgl_build_tests_234_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_235_prog",
      &GenFglTest::fgl_build_tests_235_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_236_prog",
      &GenFglTest::fgl_build_tests_236_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_237_prog",
      &GenFglTest::fgl_build_tests_237_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_238_prog",
      &GenFglTest::fgl_build_tests_238_prog ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_300_hello",
      &GenFglTest::fgl_build_tests_300_hello ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_301_database_globals",
      &GenFglTest::fgl_build_tests_301_database_globals ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_301_globals",
      &GenFglTest::fgl_build_tests_301_globals ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_301_m_database_globals",
      &GenFglTest::fgl_build_tests_301_m_database_globals ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_302_db_glob_mod_func",
      &GenFglTest::fgl_build_tests_302_db_glob_mod_func ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_302_globals",
      &GenFglTest::fgl_build_tests_302_globals ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_302_m_db_glob_mod_func",
      &GenFglTest::fgl_build_tests_302_m_db_glob_mod_func ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_303_database_modular",
      &GenFglTest::fgl_build_tests_303_database_modular ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_303_m_database_modular",
      &GenFglTest::fgl_build_tests_303_m_database_modular ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_304_empty",
      &GenFglTest::fgl_build_tests_304_empty ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_304_m_empty",
      &GenFglTest::fgl_build_tests_304_m_empty ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_305_empty_function",
      &GenFglTest::fgl_build_tests_305_empty_function ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_306_global_include_global_var",
      &GenFglTest::fgl_build_tests_306_global_include_global_var ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_306_globals",
      &GenFglTest::fgl_build_tests_306_globals ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_306_globals_two",
      &GenFglTest::fgl_build_tests_306_globals_two ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_307_global_modular_function",
      &GenFglTest::fgl_build_tests_307_global_modular_function ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_307_globals",
      &GenFglTest::fgl_build_tests_307_globals ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_308_modular_function",
      &GenFglTest::fgl_build_tests_308_modular_function ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_309_only_database",
      &GenFglTest::fgl_build_tests_309_only_database ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_310_only_function",
      &GenFglTest::fgl_build_tests_310_only_function ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_311_only_global_include",
      &GenFglTest::fgl_build_tests_311_only_global_include ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_311_globals",
      &GenFglTest::fgl_build_tests_311_globals ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_312_only_global_var",
      &GenFglTest::fgl_build_tests_312_only_global_var ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_313_only_main",
      &GenFglTest::fgl_build_tests_313_only_main ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_314_only_modular_var",
      &GenFglTest::fgl_build_tests_314_only_modular_var ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_315_three_global_include",
      &GenFglTest::fgl_build_tests_315_three_global_include ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_315_globals",
      &GenFglTest::fgl_build_tests_315_globals ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_315_globals_two",
      &GenFglTest::fgl_build_tests_315_globals_two ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_315_globals_three",
      &GenFglTest::fgl_build_tests_315_globals_three ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_316_modular_reserved_var",
      &GenFglTest::fgl_build_tests_316_modular_reserved_var ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_392_current_window_with_name",
      &GenFglTest::fgl_build_tests_392_current_window_with_name ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_393_current_window_is_screen",
      &GenFglTest::fgl_build_tests_393_current_window_is_screen ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_317_simple_call",
      &GenFglTest::fgl_build_tests_317_simple_call ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_318_call_on_parameter",
      &GenFglTest::fgl_build_tests_318_call_on_parameter ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_319_call_severall_parameter",
      &GenFglTest::fgl_build_tests_319_call_severall_parameter ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_320_call_one_return",
      &GenFglTest::fgl_build_tests_320_call_one_return ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_321_call_severall_return",
      &GenFglTest::fgl_build_tests_321_call_severall_return ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_322_call_several_param_return",
      &GenFglTest::fgl_build_tests_322_call_several_param_return ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_323_simple_case",
      &GenFglTest::fgl_build_tests_323_simple_case ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_324_empty_case",
      &GenFglTest::fgl_build_tests_324_empty_case ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_325_case_when_expression",
      &GenFglTest::fgl_build_tests_325_case_when_expression ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_326_case_otherwise",
      &GenFglTest::fgl_build_tests_326_case_otherwise ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_327_db_in_function",
      &GenFglTest::fgl_build_tests_327_db_in_function ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_328_simple_for",
      &GenFglTest::fgl_build_tests_328_simple_for ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_329_for_with_step",
      &GenFglTest::fgl_build_tests_329_for_with_step ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_330_for_with_exit_for",
      &GenFglTest::fgl_build_tests_330_for_with_exit_for ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_331_simple_foreach",
      &GenFglTest::fgl_build_tests_331_simple_foreach ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_332_foreach_one_var",
      &GenFglTest::fgl_build_tests_332_foreach_one_var ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_333_foreach_two_vars",
      &GenFglTest::fgl_build_tests_333_foreach_two_vars ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_334_foreach_continue",
      &GenFglTest::fgl_build_tests_334_foreach_continue ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_335_foreach_exit",
      &GenFglTest::fgl_build_tests_335_foreach_exit ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_336_empty_foreach",
      &GenFglTest::fgl_build_tests_336_empty_foreach ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_337_label_goto",
      &GenFglTest::fgl_build_tests_337_label_goto ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_338_simple_while",
      &GenFglTest::fgl_build_tests_338_simple_while ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_339_empty_while",
      &GenFglTest::fgl_build_tests_339_empty_while ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_340_while_with_exit",
      &GenFglTest::fgl_build_tests_340_while_with_exit ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_341_while_with_continue",
      &GenFglTest::fgl_build_tests_341_while_with_continue ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_342_simple_if",
      &GenFglTest::fgl_build_tests_342_simple_if ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_343_empty_if",
      &GenFglTest::fgl_build_tests_343_empty_if ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_344_if_else",
      &GenFglTest::fgl_build_tests_344_if_else ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_345_if_empty_else",
      &GenFglTest::fgl_build_tests_345_if_empty_else ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_346_if_several_level",
      &GenFglTest::fgl_build_tests_346_if_several_level ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_347_simple_report",
      &GenFglTest::fgl_build_tests_347_simple_report ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_348_simple_report_usage",
      &GenFglTest::fgl_build_tests_348_simple_report_usage ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_349_start_report_kinds",
      &GenFglTest::fgl_build_tests_349_start_report_kinds ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_350_report_one_parameter",
      &GenFglTest::fgl_build_tests_350_report_one_parameter ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_351_report_several_parameters",
      &GenFglTest::fgl_build_tests_351_report_several_parameters ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_352_database_in_function",
      &GenFglTest::fgl_build_tests_352_database_in_function ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_354_database_in_main",
      &GenFglTest::fgl_build_tests_354_database_in_main ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_355_defer_interrupt",
      &GenFglTest::fgl_build_tests_355_defer_interrupt ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_356_defer_quit",
      &GenFglTest::fgl_build_tests_356_defer_quit ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_357_whenever_error_stop",
      &GenFglTest::fgl_build_tests_357_whenever_error_stop ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_358_whenever_error_call",
      &GenFglTest::fgl_build_tests_358_whenever_error_call ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_359_whenever_error_goto",
      &GenFglTest::fgl_build_tests_359_whenever_error_goto ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_360_whenever_warning_stop",
      &GenFglTest::fgl_build_tests_360_whenever_warning_stop ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_361_whenever_warning_call",
      &GenFglTest::fgl_build_tests_361_whenever_warning_call ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_362_whenever_warning_goto",
      &GenFglTest::fgl_build_tests_362_whenever_warning_goto ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_363_whenever_any_error",
      &GenFglTest::fgl_build_tests_363_whenever_any_error ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_364_whenever_sqlwarning",
      &GenFglTest::fgl_build_tests_364_whenever_sqlwarning ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_365_whenever_sqlerror",
      &GenFglTest::fgl_build_tests_365_whenever_sqlerror ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_366_whenever_not_found",
      &GenFglTest::fgl_build_tests_366_whenever_not_found ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_367_whenever_error_continue",
      &GenFglTest::fgl_build_tests_367_whenever_error_continue ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_368_simple_initialize",
      &GenFglTest::fgl_build_tests_368_simple_initialize ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_369_initialize_list",
      &GenFglTest::fgl_build_tests_369_initialize_list ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_370_initialize_star",
      &GenFglTest::fgl_build_tests_370_initialize_star ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_371_simple_initialize_like",
      &GenFglTest::fgl_build_tests_371_simple_initialize_like ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_353_database_glob_and_func",
      &GenFglTest::fgl_build_tests_353_database_glob_and_func ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_372_list_initialize_like",
      &GenFglTest::fgl_build_tests_372_list_initialize_like ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_373_list_initialize_like_star",
      &GenFglTest::fgl_build_tests_373_list_initialize_like_star ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_374_simple_validate",
      &GenFglTest::fgl_build_tests_374_simple_validate ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_375_list_validate_like",
      &GenFglTest::fgl_build_tests_375_list_validate_like ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_376_list_validate_like_star",
      &GenFglTest::fgl_build_tests_376_list_validate_like_star ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_377_list_validate_with_table_qualifier",
      &GenFglTest::fgl_build_tests_377_list_validate_with_table_qualifier ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_378_simple_locate_in_memory",
      &GenFglTest::fgl_build_tests_378_simple_locate_in_memory ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_379_simple_locate_in_file",
      &GenFglTest::fgl_build_tests_379_simple_locate_in_file ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_380_list_locate_in_memory",
      &GenFglTest::fgl_build_tests_380_list_locate_in_memory ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_381_list_locate_in_file",
      &GenFglTest::fgl_build_tests_381_list_locate_in_file ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_382_simple_open_window_with_dim",
      &GenFglTest::fgl_build_tests_382_simple_open_window_with_dim ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_383_open_window_with_dim_attr",
      &GenFglTest::fgl_build_tests_383_open_window_with_dim_attr ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_384_open_window_with_form",
      &GenFglTest::fgl_build_tests_384_open_window_with_form ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_385_open_window_with_form_attr",
      &GenFglTest::fgl_build_tests_385_open_window_with_form_attr ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_386_open_form",
      &GenFglTest::fgl_build_tests_386_open_form ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_387_close_window",
      &GenFglTest::fgl_build_tests_387_close_window ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_388_close_form",
      &GenFglTest::fgl_build_tests_388_close_form ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_390_sleep_var",
      &GenFglTest::fgl_build_tests_390_sleep_var ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_391_sleep_expr",
      &GenFglTest::fgl_build_tests_391_sleep_expr ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_389_sleep_constant",
      &GenFglTest::fgl_build_tests_389_sleep_constant ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_394_clear_window_with_name",
      &GenFglTest::fgl_build_tests_394_clear_window_with_name ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_495_run_without_waiting",
      &GenFglTest::fgl_build_tests_495_run_without_waiting ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_396_clear_form",
      &GenFglTest::fgl_build_tests_396_clear_form ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_397_clear_single_field",
      &GenFglTest::fgl_build_tests_397_clear_single_field ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_398_clear_several_fields",
      &GenFglTest::fgl_build_tests_398_clear_several_fields ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_399_error_simple_string",
      &GenFglTest::fgl_build_tests_399_error_simple_string ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_400_error_with_variable",
      &GenFglTest::fgl_build_tests_400_error_with_variable ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_401_error_with_list",
      &GenFglTest::fgl_build_tests_401_error_with_list ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_402_error_all_attributes",
      &GenFglTest::fgl_build_tests_402_error_all_attributes ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_403_simple_display_form",
      &GenFglTest::fgl_build_tests_403_simple_display_form ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_404_display_for_attributes",
      &GenFglTest::fgl_build_tests_404_display_for_attributes ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_405_message_with_string",
      &GenFglTest::fgl_build_tests_405_message_with_string ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_406_message_with_variable",
      &GenFglTest::fgl_build_tests_406_message_with_variable ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_407_message_with_list",
      &GenFglTest::fgl_build_tests_407_message_with_list ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_408_message_with_attributes",
      &GenFglTest::fgl_build_tests_408_message_with_attributes ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_409_option_comment_line",
      &GenFglTest::fgl_build_tests_409_option_comment_line ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_410_option_error_line",
      &GenFglTest::fgl_build_tests_410_option_error_line ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_411_option_form_line",
      &GenFglTest::fgl_build_tests_411_option_form_line ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_432_prompt_with_list",
      &GenFglTest::fgl_build_tests_432_prompt_with_list ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_433_prompt_with_attribute",
      &GenFglTest::fgl_build_tests_433_prompt_with_attribute ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_395_clear_screen",
      &GenFglTest::fgl_build_tests_395_clear_screen ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_412_menu_line_option",
      &GenFglTest::fgl_build_tests_412_menu_line_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_413_message_line_option",
      &GenFglTest::fgl_build_tests_413_message_line_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_414_prompt_line_option",
      &GenFglTest::fgl_build_tests_414_prompt_line_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_415_accept_key_option",
      &GenFglTest::fgl_build_tests_415_accept_key_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_416_delete_key_option",
      &GenFglTest::fgl_build_tests_416_delete_key_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_417_insert_key_option",
      &GenFglTest::fgl_build_tests_417_insert_key_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_418_next_key_option",
      &GenFglTest::fgl_build_tests_418_next_key_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_419_previous_key_option",
      &GenFglTest::fgl_build_tests_419_previous_key_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_420_help_key_option",
      &GenFglTest::fgl_build_tests_420_help_key_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_421_display_attribute_option",
      &GenFglTest::fgl_build_tests_421_display_attribute_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_422_input_attribute_option",
      &GenFglTest::fgl_build_tests_422_input_attribute_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_423_input_wrap_option",
      &GenFglTest::fgl_build_tests_423_input_wrap_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_424_input_no_wrap_option",
      &GenFglTest::fgl_build_tests_424_input_no_wrap_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_425_field_order_unconstrained_option",
      &GenFglTest::fgl_build_tests_425_field_order_unconstrained_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_426_field_order_constrained_option",
      &GenFglTest::fgl_build_tests_426_field_order_constrained_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_427_sql_interrupt_on_option",
      &GenFglTest::fgl_build_tests_427_sql_interrupt_on_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_428_sql_interrupt_off_option",
      &GenFglTest::fgl_build_tests_428_sql_interrupt_off_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_429_simple_prompt",
      &GenFglTest::fgl_build_tests_429_simple_prompt ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_430_prompt_with_string",
      &GenFglTest::fgl_build_tests_430_prompt_with_string ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_431_prompt_with_variable",
      &GenFglTest::fgl_build_tests_431_prompt_with_variable ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_434_prompt_for_char",
      &GenFglTest::fgl_build_tests_434_prompt_for_char ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_436_prompt_with_ans_attribute",
      &GenFglTest::fgl_build_tests_436_prompt_with_ans_attribute ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_437_prompt_with_on_key",
      &GenFglTest::fgl_build_tests_437_prompt_with_on_key ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_438_complex_prompt",
      &GenFglTest::fgl_build_tests_438_complex_prompt ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_439_simple_menu",
      &GenFglTest::fgl_build_tests_439_simple_menu ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_440_menu_with_var_title",
      &GenFglTest::fgl_build_tests_440_menu_with_var_title ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_441_menu_with_next_option",
      &GenFglTest::fgl_build_tests_441_menu_with_next_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_442_menu_show_hide_option",
      &GenFglTest::fgl_build_tests_442_menu_show_hide_option ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_445_menu_with_continue",
      &GenFglTest::fgl_build_tests_445_menu_with_continue ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_447_menu_with_key",
      &GenFglTest::fgl_build_tests_447_menu_with_key ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_448_menu_with_help",
      &GenFglTest::fgl_build_tests_448_menu_with_help ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_449_menu_without_descriptions",
      &GenFglTest::fgl_build_tests_449_menu_without_descriptions ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_450_menu_empty_command",
      &GenFglTest::fgl_build_tests_450_menu_empty_command ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_451_menu_with_before_menu",
      &GenFglTest::fgl_build_tests_451_menu_with_before_menu ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_435_prompt_with_help",
      &GenFglTest::fgl_build_tests_435_prompt_with_help ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_452_complex_menu",
      &GenFglTest::fgl_build_tests_452_complex_menu ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_453_menu_hide_show_all",
      &GenFglTest::fgl_build_tests_453_menu_hide_show_all ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_454_simple_display",
      &GenFglTest::fgl_build_tests_454_simple_display ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_455_display_char_variable",
      &GenFglTest::fgl_build_tests_455_display_char_variable ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_456_display_all_variable_type",
      &GenFglTest::fgl_build_tests_456_display_all_variable_type ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_457_display_line_mode_column",
      &GenFglTest::fgl_build_tests_457_display_line_mode_column ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_458_simple_display_at",
      &GenFglTest::fgl_build_tests_458_simple_display_at ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_459_display_at_with_variable",
      &GenFglTest::fgl_build_tests_459_display_at_with_variable ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_460_display_at_coord_expression",
      &GenFglTest::fgl_build_tests_460_display_at_coord_expression ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_461_display_at_attributes",
      &GenFglTest::fgl_build_tests_461_display_at_attributes ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_462_display_clipped",
      &GenFglTest::fgl_build_tests_462_display_clipped ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_463_display_using",
      &GenFglTest::fgl_build_tests_463_display_using ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_464_display_ascii",
      &GenFglTest::fgl_build_tests_464_display_ascii ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_465_simple_display",
      &GenFglTest::fgl_build_tests_465_simple_display ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_466_display_by_name_one_var",
      &GenFglTest::fgl_build_tests_466_display_by_name_one_var ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_467_display_by_name_list",
      &GenFglTest::fgl_build_tests_467_display_by_name_list ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_496_input_array",
      &GenFglTest::fgl_build_tests_496_input_array ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_480_define_array_simple_type",
      &GenFglTest::fgl_build_tests_480_define_array_simple_type ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_481_define_array_of_record",
      &GenFglTest::fgl_build_tests_481_define_array_of_record ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_497_let_simple_data_type",
      &GenFglTest::fgl_build_tests_497_let_simple_data_type ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_468_display_by_name_one_field",
      &GenFglTest::fgl_build_tests_468_display_by_name_one_field ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_482_define_array_of_lob",
      &GenFglTest::fgl_build_tests_482_define_array_of_lob ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_483_record_one_variable",
      &GenFglTest::fgl_build_tests_483_record_one_variable ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_485_define_record_of_record",
      &GenFglTest::fgl_build_tests_485_define_record_of_record ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_486_scroll_down_one_field",
      &GenFglTest::fgl_build_tests_486_scroll_down_one_field ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_469_display_to_with_list",
      &GenFglTest::fgl_build_tests_469_display_to_with_list ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_470_display_to_all_attributes",
      &GenFglTest::fgl_build_tests_470_display_to_all_attributes ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_471_display_by_name_all_attributes",
      &GenFglTest::fgl_build_tests_471_display_by_name_all_attributes ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_472_simple_display_array",
      &GenFglTest::fgl_build_tests_472_simple_display_array ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_473_display_array_all_attributes",
      &GenFglTest::fgl_build_tests_473_display_array_all_attributes ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_474_display_array_on_key",
      &GenFglTest::fgl_build_tests_474_display_array_on_key ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_475_complex_display_array",
      &GenFglTest::fgl_build_tests_475_complex_display_array ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_476_define_like_column",
      &GenFglTest::fgl_build_tests_476_define_like_column ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_477_define_like_star",
      &GenFglTest::fgl_build_tests_477_define_like_star ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_478_define_table_qualifier",
      &GenFglTest::fgl_build_tests_478_define_table_qualifier ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_479_define_simple_data_type",
      &GenFglTest::fgl_build_tests_479_define_simple_data_type ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_487_scroll_down_field_list",
      &GenFglTest::fgl_build_tests_487_scroll_down_field_list ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_488_scroll_up_field_list",
      &GenFglTest::fgl_build_tests_488_scroll_up_field_list ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_489_scroll_severall_lines",
      &GenFglTest::fgl_build_tests_489_scroll_severall_lines ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_490_scroll_variable_lines",
      &GenFglTest::fgl_build_tests_490_scroll_variable_lines ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_492_simple_run",
      &GenFglTest::fgl_build_tests_492_simple_run ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_493_run_with_var",
      &GenFglTest::fgl_build_tests_493_run_with_var ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_494_run_with_returning",
      &GenFglTest::fgl_build_tests_494_run_with_returning ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_498_simple_input",
      &GenFglTest::fgl_build_tests_498_simple_input ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_499_input_from_with_list",
      &GenFglTest::fgl_build_tests_499_input_from_with_list ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_500_input_by_name_one_field",
      &GenFglTest::fgl_build_tests_500_input_by_name_one_field ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_501_input_by_name_list",
      &GenFglTest::fgl_build_tests_501_input_by_name_list ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_502_input_from_without_defaults",
      &GenFglTest::fgl_build_tests_502_input_from_without_defaults ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_503_input_by_name_without_defaults",
      &GenFglTest::fgl_build_tests_503_input_by_name_without_defaults ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_504_input_all_attributes",
      &GenFglTest::fgl_build_tests_504_input_all_attributes ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_505_input_with_help",
      &GenFglTest::fgl_build_tests_505_input_with_help ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_506_input_with_after_input",
      &GenFglTest::fgl_build_tests_506_input_with_after_input ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_507_input_by_name_without_defaults",
      &GenFglTest::fgl_build_tests_507_input_by_name_without_defaults ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_508_input_with_after_field",
      &GenFglTest::fgl_build_tests_508_input_with_after_field ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_510_input_with_before_input",
      &GenFglTest::fgl_build_tests_510_input_with_before_input ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_512_complex_input",
      &GenFglTest::fgl_build_tests_512_complex_input ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_build_tests_513_simple_construct",
      &GenFglTest::fgl_build_tests_513_simple_construct ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_P34k",
      &GenFglTest::fgl_andrej_P34k ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_P6A",
      &GenFglTest::fgl_andrej_P6A ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_P71",
      &GenFglTest::fgl_andrej_P71 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_P71f",
      &GenFglTest::fgl_andrej_P71f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_P72",
      &GenFglTest::fgl_andrej_P72 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_P73",
      &GenFglTest::fgl_andrej_P73 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PA8",
      &GenFglTest::fgl_andrej_PA8 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PAB",
      &GenFglTest::fgl_andrej_PAB ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PB1",
      &GenFglTest::fgl_andrej_PB1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PB6",
      &GenFglTest::fgl_andrej_PB6 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PC4",
      &GenFglTest::fgl_andrej_PC4 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PCA",
      &GenFglTest::fgl_andrej_PCA ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PCD",
      &GenFglTest::fgl_andrej_PCD ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PR1",
      &GenFglTest::fgl_andrej_PR1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PR2",
      &GenFglTest::fgl_andrej_PR2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PRE",
      &GenFglTest::fgl_andrej_PRE ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_PX3_J",
      &GenFglTest::fgl_andrej_PX3_J ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A21f",
      &GenFglTest::fgl_andrej_A21f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A23_J",
      &GenFglTest::fgl_andrej_A23_J ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A2S",
      &GenFglTest::fgl_andrej_A2S ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A2Sa",
      &GenFglTest::fgl_andrej_A2Sa ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A2Sb",
      &GenFglTest::fgl_andrej_A2Sb ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A2Sc",
      &GenFglTest::fgl_andrej_A2Sc ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A2Sd",
      &GenFglTest::fgl_andrej_A2Sd ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A2Se",
      &GenFglTest::fgl_andrej_A2Se ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A2Sf",
      &GenFglTest::fgl_andrej_A2Sf ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A2Sg",
      &GenFglTest::fgl_andrej_A2Sg ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_A43_J",
      &GenFglTest::fgl_andrej_A43_J ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AA9",
      &GenFglTest::fgl_andrej_AA9 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AAB",
      &GenFglTest::fgl_andrej_AAB ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AAB_B",
      &GenFglTest::fgl_andrej_AAB_B ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AAC",
      &GenFglTest::fgl_andrej_AAC ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AAE",
      &GenFglTest::fgl_andrej_AAE ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AAK",
      &GenFglTest::fgl_andrej_AAK ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AC1",
      &GenFglTest::fgl_andrej_AC1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AC2",
      &GenFglTest::fgl_andrej_AC2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AC3",
      &GenFglTest::fgl_andrej_AC3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AC4",
      &GenFglTest::fgl_andrej_AC4 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AC5",
      &GenFglTest::fgl_andrej_AC5 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AC8",
      &GenFglTest::fgl_andrej_AC8 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ACA",
      &GenFglTest::fgl_andrej_ACA ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ADU",
      &GenFglTest::fgl_andrej_ADU ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AE6",
      &GenFglTest::fgl_andrej_AE6 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AE7",
      &GenFglTest::fgl_andrej_AE7 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AE8",
      &GenFglTest::fgl_andrej_AE8 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AE9",
      &GenFglTest::fgl_andrej_AE9 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AED",
      &GenFglTest::fgl_andrej_AED ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AEE",
      &GenFglTest::fgl_andrej_AEE ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AS5",
      &GenFglTest::fgl_andrej_AS5 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ASI_J",
      &GenFglTest::fgl_andrej_ASI_J ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ASLa",
      &GenFglTest::fgl_andrej_ASLa ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ASS_J",
      &GenFglTest::fgl_andrej_ASS_J ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ASV",
      &GenFglTest::fgl_andrej_ASV ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ASV_J",
      &GenFglTest::fgl_andrej_ASV_J ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ASW",
      &GenFglTest::fgl_andrej_ASW ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_AZS",
      &GenFglTest::fgl_andrej_AZS ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact",
      &GenFglTest::fgl_andrej_contact ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact_address",
      &GenFglTest::fgl_andrej_contact_address ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact_bank",
      &GenFglTest::fgl_andrej_contact_bank ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact_cc",
      &GenFglTest::fgl_andrej_contact_cc ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact_comment",
      &GenFglTest::fgl_andrej_contact_comment ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact_glob",
      &GenFglTest::fgl_andrej_contact_glob ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact_lib",
      &GenFglTest::fgl_andrej_contact_lib ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact_mailing",
      &GenFglTest::fgl_andrej_contact_mailing ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact_phone",
      &GenFglTest::fgl_andrej_contact_phone ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact_relation",
      &GenFglTest::fgl_andrej_contact_relation ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_contact_role",
      &GenFglTest::fgl_andrej_contact_role ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_maintain",
      &GenFglTest::fgl_andrej_maintain ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_cacdwind",
      &GenFglTest::fgl_andrej_cacdwind ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_glob_DATABASE",
      &GenFglTest::fgl_andrej_glob_DATABASE ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_glob_GLOBALS",
      &GenFglTest::fgl_andrej_glob_GLOBALS ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_invbox",
      &GenFglTest::fgl_andrej_invbox ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_orddfunc",
      &GenFglTest::fgl_andrej_orddfunc ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_secufunc",
      &GenFglTest::fgl_andrej_secufunc ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_serrwind",
      &GenFglTest::fgl_andrej_serrwind ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_tablefunc",
      &GenFglTest::fgl_andrej_tablefunc ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_vopawind",
      &GenFglTest::fgl_andrej_vopawind ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_E11h",
      &GenFglTest::fgl_andrej_E11h ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_E11j",
      &GenFglTest::fgl_andrej_E11j ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_E53a",
      &GenFglTest::fgl_andrej_E53a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_E53b",
      &GenFglTest::fgl_andrej_E53b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_E54a",
      &GenFglTest::fgl_andrej_E54a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_E5B",
      &GenFglTest::fgl_andrej_E5B ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_E91",
      &GenFglTest::fgl_andrej_E91 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_E9D",
      &GenFglTest::fgl_andrej_E9D ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ER1",
      &GenFglTest::fgl_andrej_ER1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ES1",
      &GenFglTest::fgl_andrej_ES1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ES1a",
      &GenFglTest::fgl_andrej_ES1a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ES1b",
      &GenFglTest::fgl_andrej_ES1b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ES1c",
      &GenFglTest::fgl_andrej_ES1c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ES2",
      &GenFglTest::fgl_andrej_ES2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ESV",
      &GenFglTest::fgl_andrej_ESV ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ET1",
      &GenFglTest::fgl_andrej_ET1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ET2",
      &GenFglTest::fgl_andrej_ET2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ET3",
      &GenFglTest::fgl_andrej_ET3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ET4",
      &GenFglTest::fgl_andrej_ET4 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ET5",
      &GenFglTest::fgl_andrej_ET5 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ET6",
      &GenFglTest::fgl_andrej_ET6 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ET7",
      &GenFglTest::fgl_andrej_ET7 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ET8",
      &GenFglTest::fgl_andrej_ET8 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ET9",
      &GenFglTest::fgl_andrej_ET9 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ETA",
      &GenFglTest::fgl_andrej_ETA ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ETB",
      &GenFglTest::fgl_andrej_ETB ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_EU1",
      &GenFglTest::fgl_andrej_EU1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_EU2",
      &GenFglTest::fgl_andrej_EU2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_EV1",
      &GenFglTest::fgl_andrej_EV1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_EV2",
      &GenFglTest::fgl_andrej_EV2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_EV3",
      &GenFglTest::fgl_andrej_EV3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_EV4",
      &GenFglTest::fgl_andrej_EV4 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_EV5",
      &GenFglTest::fgl_andrej_EV5 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_EV6",
      &GenFglTest::fgl_andrej_EV6 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_EW1",
      &GenFglTest::fgl_andrej_EW1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_EW2",
      &GenFglTest::fgl_andrej_EW2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_F20",
      &GenFglTest::fgl_andrej_F20 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_F28",
      &GenFglTest::fgl_andrej_F28 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_F36",
      &GenFglTest::fgl_andrej_F36 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_F37",
      &GenFglTest::fgl_andrej_F37 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_F61",
      &GenFglTest::fgl_andrej_F61 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_F81",
      &GenFglTest::fgl_andrej_F81 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_F84",
      &GenFglTest::fgl_andrej_F84 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_fabatupd",
      &GenFglTest::fgl_andrej_fabatupd ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_FGL",
      &GenFglTest::fgl_andrej_FGL ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_FP1",
      &GenFglTest::fgl_andrej_FP1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_FP2",
      &GenFglTest::fgl_andrej_FP2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_G21",
      &GenFglTest::fgl_andrej_G21 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_G21a",
      &GenFglTest::fgl_andrej_G21a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_G22",
      &GenFglTest::fgl_andrej_G22 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_G27",
      &GenFglTest::fgl_andrej_G27 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_G27a",
      &GenFglTest::fgl_andrej_G27a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_G28",
      &GenFglTest::fgl_andrej_G28 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_G29",
      &GenFglTest::fgl_andrej_G29 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_G2R",
      &GenFglTest::fgl_andrej_G2R ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_G33",
      &GenFglTest::fgl_andrej_G33 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GA8",
      &GenFglTest::fgl_andrej_GA8 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GB1",
      &GenFglTest::fgl_andrej_GB1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GB8",
      &GenFglTest::fgl_andrej_GB8 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GC1",
      &GenFglTest::fgl_andrej_GC1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GC1a",
      &GenFglTest::fgl_andrej_GC1a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GC2",
      &GenFglTest::fgl_andrej_GC2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GC3",
      &GenFglTest::fgl_andrej_GC3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GC5",
      &GenFglTest::fgl_andrej_GC5 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GCEb",
      &GenFglTest::fgl_andrej_GCEb ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GCEd",
      &GenFglTest::fgl_andrej_GCEd ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GCEe",
      &GenFglTest::fgl_andrej_GCEe ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GCP",
      &GenFglTest::fgl_andrej_GCP ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GRH",
      &GenFglTest::fgl_andrej_GRH ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GRI",
      &GenFglTest::fgl_andrej_GRI ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GRJ",
      &GenFglTest::fgl_andrej_GRJ ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GS1",
      &GenFglTest::fgl_andrej_GS1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW1c",
      &GenFglTest::fgl_andrej_GW1c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW1d",
      &GenFglTest::fgl_andrej_GW1d ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW3",
      &GenFglTest::fgl_andrej_GW3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW3a",
      &GenFglTest::fgl_andrej_GW3a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW3b",
      &GenFglTest::fgl_andrej_GW3b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW3c",
      &GenFglTest::fgl_andrej_GW3c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW3d",
      &GenFglTest::fgl_andrej_GW3d ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW3e",
      &GenFglTest::fgl_andrej_GW3e ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW3f",
      &GenFglTest::fgl_andrej_GW3f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW3g",
      &GenFglTest::fgl_andrej_GW3g ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW4a",
      &GenFglTest::fgl_andrej_GW4a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GW6a",
      &GenFglTest::fgl_andrej_GW6a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_GZD",
      &GenFglTest::fgl_andrej_GZD ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW1c",
      &GenFglTest::fgl_andrej_TGW1c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW1d",
      &GenFglTest::fgl_andrej_TGW1d ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW3",
      &GenFglTest::fgl_andrej_TGW3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW3a",
      &GenFglTest::fgl_andrej_TGW3a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW3b",
      &GenFglTest::fgl_andrej_TGW3b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW3c",
      &GenFglTest::fgl_andrej_TGW3c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW3d",
      &GenFglTest::fgl_andrej_TGW3d ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW3e",
      &GenFglTest::fgl_andrej_TGW3e ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW3f",
      &GenFglTest::fgl_andrej_TGW3f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW3g",
      &GenFglTest::fgl_andrej_TGW3g ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_TGW6a",
      &GenFglTest::fgl_andrej_TGW6a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_I11",
      &GenFglTest::fgl_andrej_I11 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_I19",
      &GenFglTest::fgl_andrej_I19 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_I22",
      &GenFglTest::fgl_andrej_I22 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_I51",
      &GenFglTest::fgl_andrej_I51 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_I51a",
      &GenFglTest::fgl_andrej_I51a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_I57",
      &GenFglTest::fgl_andrej_I57 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_I5B",
      &GenFglTest::fgl_andrej_I5B ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_I5C",
      &GenFglTest::fgl_andrej_I5C ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_I5D",
      &GenFglTest::fgl_andrej_I5D ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_I5T",
      &GenFglTest::fgl_andrej_I5T ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IA",
      &GenFglTest::fgl_andrej_IA ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IAE",
      &GenFglTest::fgl_andrej_IAE ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IAF",
      &GenFglTest::fgl_andrej_IAF ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IAG",
      &GenFglTest::fgl_andrej_IAG ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IB",
      &GenFglTest::fgl_andrej_IB ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IB3",
      &GenFglTest::fgl_andrej_IB3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IBS",
      &GenFglTest::fgl_andrej_IBS ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IBT",
      &GenFglTest::fgl_andrej_IBT ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IC1",
      &GenFglTest::fgl_andrej_IC1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IC2",
      &GenFglTest::fgl_andrej_IC2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IC3",
      &GenFglTest::fgl_andrej_IC3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IC5",
      &GenFglTest::fgl_andrej_IC5 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ICG",
      &GenFglTest::fgl_andrej_ICG ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ID8",
      &GenFglTest::fgl_andrej_ID8 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IR",
      &GenFglTest::fgl_andrej_IR ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IR2",
      &GenFglTest::fgl_andrej_IR2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IS2",
      &GenFglTest::fgl_andrej_IS2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IS3",
      &GenFglTest::fgl_andrej_IS3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IS9",
      &GenFglTest::fgl_andrej_IS9 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ISM",
      &GenFglTest::fgl_andrej_ISM ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_ISV",
      &GenFglTest::fgl_andrej_ISV ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IT3",
      &GenFglTest::fgl_andrej_IT3 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_IU1",
      &GenFglTest::fgl_andrej_IU1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J15",
      &GenFglTest::fgl_andrej_J15 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J18",
      &GenFglTest::fgl_andrej_J18 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J27a",
      &GenFglTest::fgl_andrej_J27a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J31",
      &GenFglTest::fgl_andrej_J31 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J31a",
      &GenFglTest::fgl_andrej_J31a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J31glob",
      &GenFglTest::fgl_andrej_J31glob ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J34",
      &GenFglTest::fgl_andrej_J34 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J36",
      &GenFglTest::fgl_andrej_J36 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J36a",
      &GenFglTest::fgl_andrej_J36a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J36b",
      &GenFglTest::fgl_andrej_J36b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J36c",
      &GenFglTest::fgl_andrej_J36c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J36e",
      &GenFglTest::fgl_andrej_J36e ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J36f",
      &GenFglTest::fgl_andrej_J36f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J36g",
      &GenFglTest::fgl_andrej_J36g ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J38",
      &GenFglTest::fgl_andrej_J38 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J38a",
      &GenFglTest::fgl_andrej_J38a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC2g",
      &GenFglTest::fgl_andrej_JC2g ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J3C",
      &GenFglTest::fgl_andrej_J3C ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J51",
      &GenFglTest::fgl_andrej_J51 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J54",
      &GenFglTest::fgl_andrej_J54 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J55",
      &GenFglTest::fgl_andrej_J55 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J77a",
      &GenFglTest::fgl_andrej_J77a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_J91",
      &GenFglTest::fgl_andrej_J91 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JA1g",
      &GenFglTest::fgl_andrej_JA1g ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JA3g",
      &GenFglTest::fgl_andrej_JA3g ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JA5g",
      &GenFglTest::fgl_andrej_JA5g ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC1",
      &GenFglTest::fgl_andrej_JC1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC1a",
      &GenFglTest::fgl_andrej_JC1a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC1b",
      &GenFglTest::fgl_andrej_JC1b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC1d",
      &GenFglTest::fgl_andrej_JC1d ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC1e",
      &GenFglTest::fgl_andrej_JC1e ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC1f",
      &GenFglTest::fgl_andrej_JC1f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC1g",
      &GenFglTest::fgl_andrej_JC1g ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC2",
      &GenFglTest::fgl_andrej_JC2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC2a",
      &GenFglTest::fgl_andrej_JC2a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC2b",
      &GenFglTest::fgl_andrej_JC2b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC2d",
      &GenFglTest::fgl_andrej_JC2d ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC2e",
      &GenFglTest::fgl_andrej_JC2e ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JC2f",
      &GenFglTest::fgl_andrej_JC2f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JR1",
      &GenFglTest::fgl_andrej_JR1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JR5",
      &GenFglTest::fgl_andrej_JR5 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JR6",
      &GenFglTest::fgl_andrej_JR6 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JR7",
      &GenFglTest::fgl_andrej_JR7 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JR8",
      &GenFglTest::fgl_andrej_JR8 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JRB",
      &GenFglTest::fgl_andrej_JRB ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JRH",
      &GenFglTest::fgl_andrej_JRH ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JRI",
      &GenFglTest::fgl_andrej_JRI ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JRM",
      &GenFglTest::fgl_andrej_JRM ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JRN",
      &GenFglTest::fgl_andrej_JRN ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JRO",
      &GenFglTest::fgl_andrej_JRO ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JRS",
      &GenFglTest::fgl_andrej_JRS ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JS1",
      &GenFglTest::fgl_andrej_JS1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_JS4c",
      &GenFglTest::fgl_andrej_JS4c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L11",
      &GenFglTest::fgl_andrej_L11 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L11a",
      &GenFglTest::fgl_andrej_L11a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L11b",
      &GenFglTest::fgl_andrej_L11b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L11c",
      &GenFglTest::fgl_andrej_L11c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L11e",
      &GenFglTest::fgl_andrej_L11e ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L11f",
      &GenFglTest::fgl_andrej_L11f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L11g",
      &GenFglTest::fgl_andrej_L11g ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L11i",
      &GenFglTest::fgl_andrej_L11i ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L11j",
      &GenFglTest::fgl_andrej_L11j ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L14",
      &GenFglTest::fgl_andrej_L14 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L14a",
      &GenFglTest::fgl_andrej_L14a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L51",
      &GenFglTest::fgl_andrej_L51 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L51a",
      &GenFglTest::fgl_andrej_L51a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L51b",
      &GenFglTest::fgl_andrej_L51b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L51c",
      &GenFglTest::fgl_andrej_L51c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L51d",
      &GenFglTest::fgl_andrej_L51d ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L51e",
      &GenFglTest::fgl_andrej_L51e ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L51f",
      &GenFglTest::fgl_andrej_L51f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L54",
      &GenFglTest::fgl_andrej_L54 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L54a",
      &GenFglTest::fgl_andrej_L54a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L61",
      &GenFglTest::fgl_andrej_L61 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L61a",
      &GenFglTest::fgl_andrej_L61a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L61b",
      &GenFglTest::fgl_andrej_L61b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L61c",
      &GenFglTest::fgl_andrej_L61c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L61d",
      &GenFglTest::fgl_andrej_L61d ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L61e",
      &GenFglTest::fgl_andrej_L61e ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L61f",
      &GenFglTest::fgl_andrej_L61f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L64",
      &GenFglTest::fgl_andrej_L64 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_L64a",
      &GenFglTest::fgl_andrej_L64a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_lcjrintf",
      &GenFglTest::fgl_andrej_lcjrintf ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M12",
      &GenFglTest::fgl_andrej_M12 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M1A",
      &GenFglTest::fgl_andrej_M1A ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M27",
      &GenFglTest::fgl_andrej_M27 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M28",
      &GenFglTest::fgl_andrej_M28 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M35",
      &GenFglTest::fgl_andrej_M35 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M41",
      &GenFglTest::fgl_andrej_M41 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M45",
      &GenFglTest::fgl_andrej_M45 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M47",
      &GenFglTest::fgl_andrej_M47 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M51a",
      &GenFglTest::fgl_andrej_M51a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M53",
      &GenFglTest::fgl_andrej_M53 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M53a",
      &GenFglTest::fgl_andrej_M53a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M55",
      &GenFglTest::fgl_andrej_M55 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M56",
      &GenFglTest::fgl_andrej_M56 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M57",
      &GenFglTest::fgl_andrej_M57 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M63",
      &GenFglTest::fgl_andrej_M63 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M74",
      &GenFglTest::fgl_andrej_M74 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_M82",
      &GenFglTest::fgl_andrej_M82 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_MS3_20",
      &GenFglTest::fgl_andrej_MS3_20 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_MZ8",
      &GenFglTest::fgl_andrej_MZ8 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_MZP",
      &GenFglTest::fgl_andrej_MZP ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_R17",
      &GenFglTest::fgl_andrej_R17 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_R21",
      &GenFglTest::fgl_andrej_R21 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_R21a",
      &GenFglTest::fgl_andrej_R21a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_R21b",
      &GenFglTest::fgl_andrej_R21b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_R21c",
      &GenFglTest::fgl_andrej_R21c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_R21d",
      &GenFglTest::fgl_andrej_R21d ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_RAE",
      &GenFglTest::fgl_andrej_RAE ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_RAF",
      &GenFglTest::fgl_andrej_RAF ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_RS1c",
      &GenFglTest::fgl_andrej_RS1c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_Q11h",
      &GenFglTest::fgl_andrej_Q11h ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_QA1",
      &GenFglTest::fgl_andrej_QA1 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_QA5",
      &GenFglTest::fgl_andrej_QA5 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_N11f",
      &GenFglTest::fgl_andrej_N11f ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_N31",
      &GenFglTest::fgl_andrej_N31 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_N41b",
      &GenFglTest::fgl_andrej_N41b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_K11e",
      &GenFglTest::fgl_andrej_K11e ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_K41",
      &GenFglTest::fgl_andrej_K41 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_K41a",
      &GenFglTest::fgl_andrej_K41a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_K41b",
      &GenFglTest::fgl_andrej_K41b ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_K41c",
      &GenFglTest::fgl_andrej_K41c ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_K41d",
      &GenFglTest::fgl_andrej_K41d ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_K41e",
      &GenFglTest::fgl_andrej_K41e ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_K47",
      &GenFglTest::fgl_andrej_K47 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_K47a",
      &GenFglTest::fgl_andrej_K47a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_KL1a",
      &GenFglTest::fgl_andrej_KL1a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_KL2a",
      &GenFglTest::fgl_andrej_KL2a ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_KS2",
      &GenFglTest::fgl_andrej_KS2 ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_xx",
      &GenFglTest::fgl_andrej_xx ) 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_andrej_yy",
      &GenFglTest::fgl_andrej_yy ) 
		);
    return suiteOfTests;
	}

  void fgl_build_tests_10_ui_contrl ();

  void fgl_build_tests_100_rep ();

  void fgl_build_tests_101_prog ();

  void fgl_build_tests_11_scr ();

  void fgl_build_tests_12_dec_round ();

  void fgl_build_tests_12_dec_round2 ();

  void fgl_build_tests_12_dec_round3 ();

  void fgl_build_tests_12_dec_round4 ();

  void fgl_build_tests_12_dec_round5 ();

  void fgl_build_tests_12_dec_round6 ();

  void fgl_build_tests_13_expr ();

  void fgl_build_tests_14_rep ();

  void fgl_build_tests_15_prompt ();

  void fgl_build_tests_202_m1 ();

  void fgl_build_tests_202_m2 ();

  void fgl_build_tests_203_m1 ();

  void fgl_build_tests_204_m1 ();

  void fgl_build_tests_205_m2 ();

  void fgl_build_tests_206_select ();

  void fgl_build_tests_207_prog ();

  void fgl_build_tests_208_prog ();

  void fgl_build_tests_209_prog ();

  void fgl_build_tests_21_rep ();

  void fgl_build_tests_210_prog ();

  void fgl_build_tests_211_prog ();

  void fgl_build_tests_212_prog ();

  void fgl_build_tests_212_prelude ();

  void fgl_build_tests_213_prog ();

  void fgl_build_tests_214_prog ();

  void fgl_build_tests_22_arr3 ();

  void fgl_build_tests_23_p1 ();

  void fgl_build_tests_24_ibt ();

  void fgl_build_tests_25_xrpt ();

  void fgl_build_tests_26_arr3a ();

  void fgl_build_tests_27_arr3b ();

  void fgl_build_tests_28_dt ();

  void fgl_build_tests_29_disp ();

  void fgl_build_tests_3_menu1 ();

  void fgl_build_tests_30_arr12 ();

  void fgl_build_tests_30_inp ();

  void fgl_build_tests_31_m1 ();

  void fgl_build_tests_32_g2 ();

  void fgl_build_tests_33_g1 ();

  void fgl_build_tests_34_g1 ();

  void fgl_build_tests_35_arith ();

  void fgl_build_tests_36_temp ();

  void fgl_build_tests_37_prompt ();

  void fgl_build_tests_38_arr3b ();

  void fgl_build_tests_39_zero ();

  void fgl_build_tests_4_prompt_err ();

  void fgl_build_tests_40_test_257 ();

  void fgl_build_tests_41_test_267 ();

  void fgl_build_tests_42_test_265 ();

  void fgl_build_tests_47_testdt_null ();

  void fgl_build_tests_48_rep ();

  void fgl_build_tests_49_t1 ();

  void fgl_build_tests_49_t2 ();

  void fgl_build_tests_49_testdt ();

  void fgl_build_tests_50_using ();

  void fgl_build_tests_51_rep ();

  void fgl_build_tests_51_x ();

  void fgl_build_tests_52_like ();

  void fgl_build_tests_53_m ();

  void fgl_build_tests_54_w ();

  void fgl_build_tests_56_k ();

  void fgl_build_tests_57_ia ();

  void fgl_build_tests_58_m1 ();

  void fgl_build_tests_59_m ();

  void fgl_build_tests_6_fgldrawbox ();

  void fgl_build_tests_60_m1 ();

  void fgl_build_tests_61_match ();

  void fgl_build_tests_62_decassign ();

  void fgl_build_tests_62_t1 ();

  void fgl_build_tests_63_constru ();

  void fgl_build_tests_64_rg ();

  void fgl_build_tests_66_decdiv ();

  void fgl_build_tests_66_t1 ();

  void fgl_build_tests_67_fgldb ();

  void fgl_build_tests_68_dtblank ();

  void fgl_build_tests_69_dt ();

  void fgl_build_tests_70_arr3a ();

  void fgl_build_tests_71_r1 ();

  void fgl_build_tests_72_r1 ();

  void fgl_build_tests_72_r2 ();

  void fgl_build_tests_73_into ();

  void fgl_build_tests_74_v ();

  void fgl_build_tests_75_r1 ();

  void fgl_build_tests_76_datetime ();

  void fgl_build_tests_77_getfld ();

  void fgl_build_tests_78_moneytype ();

  void fgl_build_tests_79_w ();

  void fgl_build_tests_8_error ();

  void fgl_build_tests_80_t ();

  void fgl_build_tests_82_rg2 ();

  void fgl_build_tests_84_chartst ();

  void fgl_build_tests_86_g1 ();

  void fgl_build_tests_9_g1 ();

  void fgl_build_tests_9_m1 ();

  void fgl_build_tests_90_using ();

  void fgl_build_tests_91_put ();

  void fgl_build_tests_92_test_271 ();

  void fgl_build_tests_93_rg1 ();

  void fgl_build_tests_94_desc ();

  void fgl_build_tests_95_m1 ();

  void fgl_build_tests_96_m1 ();

  void fgl_build_tests_97_testna ();

  void fgl_build_tests_98_testna ();

  void fgl_build_tests_99_in ();

  void fgl_build_tests_99_in_db ();

  void fgl_build_tests_template_prog ();

  void fgl_build_tests_1_simple_null ();

  void fgl_build_tests_215_prog ();

  void fgl_build_tests_216_prog ();

  void fgl_build_tests_217_prog ();

  void fgl_build_tests_217_prog2 ();

  void fgl_build_tests_218_rpc_client ();

  void fgl_build_tests_218_rpc_server ();

  void fgl_build_tests_219_prog ();

  void fgl_build_tests_220_prog ();

  void fgl_build_tests_221_prog ();

  void fgl_build_tests_222_prog ();

  void fgl_build_tests_223_prog ();

  void fgl_build_tests_224_prog ();

  void fgl_build_tests_225_prog ();

  void fgl_build_tests_226_prog ();

  void fgl_build_tests_227_prog ();

  void fgl_build_tests_228_prog ();

  void fgl_build_tests_229_prog ();

  void fgl_build_tests_230_prog ();

  void fgl_build_tests_231_prog ();

  void fgl_build_tests_232_prog ();

  void fgl_build_tests_233_prog ();

  void fgl_build_tests_234_prog ();

  void fgl_build_tests_235_prog ();

  void fgl_build_tests_236_prog ();

  void fgl_build_tests_237_prog ();

  void fgl_build_tests_238_prog ();

  void fgl_build_tests_300_hello ();

  void fgl_build_tests_301_database_globals ();

  void fgl_build_tests_301_globals ();

  void fgl_build_tests_301_m_database_globals ();

  void fgl_build_tests_302_db_glob_mod_func ();

  void fgl_build_tests_302_globals ();

  void fgl_build_tests_302_m_db_glob_mod_func ();

  void fgl_build_tests_303_database_modular ();

  void fgl_build_tests_303_m_database_modular ();

  void fgl_build_tests_304_empty ();

  void fgl_build_tests_304_m_empty ();

  void fgl_build_tests_305_empty_function ();

  void fgl_build_tests_306_global_include_global_var ();

  void fgl_build_tests_306_globals ();

  void fgl_build_tests_306_globals_two ();

  void fgl_build_tests_307_global_modular_function ();

  void fgl_build_tests_307_globals ();

  void fgl_build_tests_308_modular_function ();

  void fgl_build_tests_309_only_database ();

  void fgl_build_tests_310_only_function ();

  void fgl_build_tests_311_only_global_include ();

  void fgl_build_tests_311_globals ();

  void fgl_build_tests_312_only_global_var ();

  void fgl_build_tests_313_only_main ();

  void fgl_build_tests_314_only_modular_var ();

  void fgl_build_tests_315_three_global_include ();

  void fgl_build_tests_315_globals ();

  void fgl_build_tests_315_globals_two ();

  void fgl_build_tests_315_globals_three ();

  void fgl_build_tests_316_modular_reserved_var ();

  void fgl_build_tests_392_current_window_with_name ();

  void fgl_build_tests_393_current_window_is_screen ();

  void fgl_build_tests_317_simple_call ();

  void fgl_build_tests_318_call_on_parameter ();

  void fgl_build_tests_319_call_severall_parameter ();

  void fgl_build_tests_320_call_one_return ();

  void fgl_build_tests_321_call_severall_return ();

  void fgl_build_tests_322_call_several_param_return ();

  void fgl_build_tests_323_simple_case ();

  void fgl_build_tests_324_empty_case ();

  void fgl_build_tests_325_case_when_expression ();

  void fgl_build_tests_326_case_otherwise ();

  void fgl_build_tests_327_db_in_function ();

  void fgl_build_tests_328_simple_for ();

  void fgl_build_tests_329_for_with_step ();

  void fgl_build_tests_330_for_with_exit_for ();

  void fgl_build_tests_331_simple_foreach ();

  void fgl_build_tests_332_foreach_one_var ();

  void fgl_build_tests_333_foreach_two_vars ();

  void fgl_build_tests_334_foreach_continue ();

  void fgl_build_tests_335_foreach_exit ();

  void fgl_build_tests_336_empty_foreach ();

  void fgl_build_tests_337_label_goto ();

  void fgl_build_tests_338_simple_while ();

  void fgl_build_tests_339_empty_while ();

  void fgl_build_tests_340_while_with_exit ();

  void fgl_build_tests_341_while_with_continue ();

  void fgl_build_tests_342_simple_if ();

  void fgl_build_tests_343_empty_if ();

  void fgl_build_tests_344_if_else ();

  void fgl_build_tests_345_if_empty_else ();

  void fgl_build_tests_346_if_several_level ();

  void fgl_build_tests_347_simple_report ();

  void fgl_build_tests_348_simple_report_usage ();

  void fgl_build_tests_349_start_report_kinds ();

  void fgl_build_tests_350_report_one_parameter ();

  void fgl_build_tests_351_report_several_parameters ();

  void fgl_build_tests_352_database_in_function ();

  void fgl_build_tests_354_database_in_main ();

  void fgl_build_tests_355_defer_interrupt ();

  void fgl_build_tests_356_defer_quit ();

  void fgl_build_tests_357_whenever_error_stop ();

  void fgl_build_tests_358_whenever_error_call ();

  void fgl_build_tests_359_whenever_error_goto ();

  void fgl_build_tests_360_whenever_warning_stop ();

  void fgl_build_tests_361_whenever_warning_call ();

  void fgl_build_tests_362_whenever_warning_goto ();

  void fgl_build_tests_363_whenever_any_error ();

  void fgl_build_tests_364_whenever_sqlwarning ();

  void fgl_build_tests_365_whenever_sqlerror ();

  void fgl_build_tests_366_whenever_not_found ();

  void fgl_build_tests_367_whenever_error_continue ();

  void fgl_build_tests_368_simple_initialize ();

  void fgl_build_tests_369_initialize_list ();

  void fgl_build_tests_370_initialize_star ();

  void fgl_build_tests_371_simple_initialize_like ();

  void fgl_build_tests_353_database_glob_and_func ();

  void fgl_build_tests_372_list_initialize_like ();

  void fgl_build_tests_373_list_initialize_like_star ();

  void fgl_build_tests_374_simple_validate ();

  void fgl_build_tests_375_list_validate_like ();

  void fgl_build_tests_376_list_validate_like_star ();

  void fgl_build_tests_377_list_validate_with_table_qualifier ();

  void fgl_build_tests_378_simple_locate_in_memory ();

  void fgl_build_tests_379_simple_locate_in_file ();

  void fgl_build_tests_380_list_locate_in_memory ();

  void fgl_build_tests_381_list_locate_in_file ();

  void fgl_build_tests_382_simple_open_window_with_dim ();

  void fgl_build_tests_383_open_window_with_dim_attr ();

  void fgl_build_tests_384_open_window_with_form ();

  void fgl_build_tests_385_open_window_with_form_attr ();

  void fgl_build_tests_386_open_form ();

  void fgl_build_tests_387_close_window ();

  void fgl_build_tests_388_close_form ();

  void fgl_build_tests_390_sleep_var ();

  void fgl_build_tests_391_sleep_expr ();

  void fgl_build_tests_389_sleep_constant ();

  void fgl_build_tests_394_clear_window_with_name ();

  void fgl_build_tests_495_run_without_waiting ();

  void fgl_build_tests_396_clear_form ();

  void fgl_build_tests_397_clear_single_field ();

  void fgl_build_tests_398_clear_several_fields ();

  void fgl_build_tests_399_error_simple_string ();

  void fgl_build_tests_400_error_with_variable ();

  void fgl_build_tests_401_error_with_list ();

  void fgl_build_tests_402_error_all_attributes ();

  void fgl_build_tests_403_simple_display_form ();

  void fgl_build_tests_404_display_for_attributes ();

  void fgl_build_tests_405_message_with_string ();

  void fgl_build_tests_406_message_with_variable ();

  void fgl_build_tests_407_message_with_list ();

  void fgl_build_tests_408_message_with_attributes ();

  void fgl_build_tests_409_option_comment_line ();

  void fgl_build_tests_410_option_error_line ();

  void fgl_build_tests_411_option_form_line ();

  void fgl_build_tests_432_prompt_with_list ();

  void fgl_build_tests_433_prompt_with_attribute ();

  void fgl_build_tests_395_clear_screen ();

  void fgl_build_tests_412_menu_line_option ();

  void fgl_build_tests_413_message_line_option ();

  void fgl_build_tests_414_prompt_line_option ();

  void fgl_build_tests_415_accept_key_option ();

  void fgl_build_tests_416_delete_key_option ();

  void fgl_build_tests_417_insert_key_option ();

  void fgl_build_tests_418_next_key_option ();

  void fgl_build_tests_419_previous_key_option ();

  void fgl_build_tests_420_help_key_option ();

  void fgl_build_tests_421_display_attribute_option ();

  void fgl_build_tests_422_input_attribute_option ();

  void fgl_build_tests_423_input_wrap_option ();

  void fgl_build_tests_424_input_no_wrap_option ();

  void fgl_build_tests_425_field_order_unconstrained_option ();

  void fgl_build_tests_426_field_order_constrained_option ();

  void fgl_build_tests_427_sql_interrupt_on_option ();

  void fgl_build_tests_428_sql_interrupt_off_option ();

  void fgl_build_tests_429_simple_prompt ();

  void fgl_build_tests_430_prompt_with_string ();

  void fgl_build_tests_431_prompt_with_variable ();

  void fgl_build_tests_434_prompt_for_char ();

  void fgl_build_tests_436_prompt_with_ans_attribute ();

  void fgl_build_tests_437_prompt_with_on_key ();

  void fgl_build_tests_438_complex_prompt ();

  void fgl_build_tests_439_simple_menu ();

  void fgl_build_tests_440_menu_with_var_title ();

  void fgl_build_tests_441_menu_with_next_option ();

  void fgl_build_tests_442_menu_show_hide_option ();

  void fgl_build_tests_445_menu_with_continue ();

  void fgl_build_tests_447_menu_with_key ();

  void fgl_build_tests_448_menu_with_help ();

  void fgl_build_tests_449_menu_without_descriptions ();

  void fgl_build_tests_450_menu_empty_command ();

  void fgl_build_tests_451_menu_with_before_menu ();

  void fgl_build_tests_435_prompt_with_help ();

  void fgl_build_tests_452_complex_menu ();

  void fgl_build_tests_453_menu_hide_show_all ();

  void fgl_build_tests_454_simple_display ();

  void fgl_build_tests_455_display_char_variable ();

  void fgl_build_tests_456_display_all_variable_type ();

  void fgl_build_tests_457_display_line_mode_column ();

  void fgl_build_tests_458_simple_display_at ();

  void fgl_build_tests_459_display_at_with_variable ();

  void fgl_build_tests_460_display_at_coord_expression ();

  void fgl_build_tests_461_display_at_attributes ();

  void fgl_build_tests_462_display_clipped ();

  void fgl_build_tests_463_display_using ();

  void fgl_build_tests_464_display_ascii ();

  void fgl_build_tests_465_simple_display ();

  void fgl_build_tests_466_display_by_name_one_var ();

  void fgl_build_tests_467_display_by_name_list ();

  void fgl_build_tests_496_input_array ();

  void fgl_build_tests_480_define_array_simple_type ();

  void fgl_build_tests_481_define_array_of_record ();

  void fgl_build_tests_497_let_simple_data_type ();

  void fgl_build_tests_468_display_by_name_one_field ();

  void fgl_build_tests_482_define_array_of_lob ();

  void fgl_build_tests_483_record_one_variable ();

  void fgl_build_tests_485_define_record_of_record ();

  void fgl_build_tests_486_scroll_down_one_field ();

  void fgl_build_tests_469_display_to_with_list ();

  void fgl_build_tests_470_display_to_all_attributes ();

  void fgl_build_tests_471_display_by_name_all_attributes ();

  void fgl_build_tests_472_simple_display_array ();

  void fgl_build_tests_473_display_array_all_attributes ();

  void fgl_build_tests_474_display_array_on_key ();

  void fgl_build_tests_475_complex_display_array ();

  void fgl_build_tests_476_define_like_column ();

  void fgl_build_tests_477_define_like_star ();

  void fgl_build_tests_478_define_table_qualifier ();

  void fgl_build_tests_479_define_simple_data_type ();

  void fgl_build_tests_487_scroll_down_field_list ();

  void fgl_build_tests_488_scroll_up_field_list ();

  void fgl_build_tests_489_scroll_severall_lines ();

  void fgl_build_tests_490_scroll_variable_lines ();

  void fgl_build_tests_492_simple_run ();

  void fgl_build_tests_493_run_with_var ();

  void fgl_build_tests_494_run_with_returning ();

  void fgl_build_tests_498_simple_input ();

  void fgl_build_tests_499_input_from_with_list ();

  void fgl_build_tests_500_input_by_name_one_field ();

  void fgl_build_tests_501_input_by_name_list ();

  void fgl_build_tests_502_input_from_without_defaults ();

  void fgl_build_tests_503_input_by_name_without_defaults ();

  void fgl_build_tests_504_input_all_attributes ();

  void fgl_build_tests_505_input_with_help ();

  void fgl_build_tests_506_input_with_after_input ();

  void fgl_build_tests_507_input_by_name_without_defaults ();

  void fgl_build_tests_508_input_with_after_field ();

  void fgl_build_tests_510_input_with_before_input ();

  void fgl_build_tests_512_complex_input ();

  void fgl_build_tests_513_simple_construct ();

  void fgl_andrej_P34k ();

  void fgl_andrej_P6A ();

  void fgl_andrej_P71 ();

  void fgl_andrej_P71f ();

  void fgl_andrej_P72 ();

  void fgl_andrej_P73 ();

  void fgl_andrej_PA8 ();

  void fgl_andrej_PAB ();

  void fgl_andrej_PB1 ();

  void fgl_andrej_PB6 ();

  void fgl_andrej_PC4 ();

  void fgl_andrej_PCA ();

  void fgl_andrej_PCD ();

  void fgl_andrej_PR1 ();

  void fgl_andrej_PR2 ();

  void fgl_andrej_PRE ();

  void fgl_andrej_PX3_J ();

  void fgl_andrej_A21f ();

  void fgl_andrej_A23_J ();

  void fgl_andrej_A2S ();

  void fgl_andrej_A2Sa ();

  void fgl_andrej_A2Sb ();

  void fgl_andrej_A2Sc ();

  void fgl_andrej_A2Sd ();

  void fgl_andrej_A2Se ();

  void fgl_andrej_A2Sf ();

  void fgl_andrej_A2Sg ();

  void fgl_andrej_A43_J ();

  void fgl_andrej_AA9 ();

  void fgl_andrej_AAB ();

  void fgl_andrej_AAB_B ();

  void fgl_andrej_AAC ();

  void fgl_andrej_AAE ();

  void fgl_andrej_AAK ();

  void fgl_andrej_AC1 ();

  void fgl_andrej_AC2 ();

  void fgl_andrej_AC3 ();

  void fgl_andrej_AC4 ();

  void fgl_andrej_AC5 ();

  void fgl_andrej_AC8 ();

  void fgl_andrej_ACA ();

  void fgl_andrej_ADU ();

  void fgl_andrej_AE6 ();

  void fgl_andrej_AE7 ();

  void fgl_andrej_AE8 ();

  void fgl_andrej_AE9 ();

  void fgl_andrej_AED ();

  void fgl_andrej_AEE ();

  void fgl_andrej_AS5 ();

  void fgl_andrej_ASI_J ();

  void fgl_andrej_ASLa ();

  void fgl_andrej_ASS_J ();

  void fgl_andrej_ASV ();

  void fgl_andrej_ASV_J ();

  void fgl_andrej_ASW ();

  void fgl_andrej_AZS ();

  void fgl_andrej_contact ();

  void fgl_andrej_contact_address ();

  void fgl_andrej_contact_bank ();

  void fgl_andrej_contact_cc ();

  void fgl_andrej_contact_comment ();

  void fgl_andrej_contact_glob ();

  void fgl_andrej_contact_lib ();

  void fgl_andrej_contact_mailing ();

  void fgl_andrej_contact_phone ();

  void fgl_andrej_contact_relation ();

  void fgl_andrej_contact_role ();

  void fgl_andrej_maintain ();

  void fgl_andrej_cacdwind ();

  void fgl_andrej_glob_DATABASE ();

  void fgl_andrej_glob_GLOBALS ();

  void fgl_andrej_invbox ();

  void fgl_andrej_orddfunc ();

  void fgl_andrej_secufunc ();

  void fgl_andrej_serrwind ();

  void fgl_andrej_tablefunc ();

  void fgl_andrej_vopawind ();

  void fgl_andrej_E11h ();

  void fgl_andrej_E11j ();

  void fgl_andrej_E53a ();

  void fgl_andrej_E53b ();

  void fgl_andrej_E54a ();

  void fgl_andrej_E5B ();

  void fgl_andrej_E91 ();

  void fgl_andrej_E9D ();

  void fgl_andrej_ER1 ();

  void fgl_andrej_ES1 ();

  void fgl_andrej_ES1a ();

  void fgl_andrej_ES1b ();

  void fgl_andrej_ES1c ();

  void fgl_andrej_ES2 ();

  void fgl_andrej_ESV ();

  void fgl_andrej_ET1 ();

  void fgl_andrej_ET2 ();

  void fgl_andrej_ET3 ();

  void fgl_andrej_ET4 ();

  void fgl_andrej_ET5 ();

  void fgl_andrej_ET6 ();

  void fgl_andrej_ET7 ();

  void fgl_andrej_ET8 ();

  void fgl_andrej_ET9 ();

  void fgl_andrej_ETA ();

  void fgl_andrej_ETB ();

  void fgl_andrej_EU1 ();

  void fgl_andrej_EU2 ();

  void fgl_andrej_EV1 ();

  void fgl_andrej_EV2 ();

  void fgl_andrej_EV3 ();

  void fgl_andrej_EV4 ();

  void fgl_andrej_EV5 ();

  void fgl_andrej_EV6 ();

  void fgl_andrej_EW1 ();

  void fgl_andrej_EW2 ();

  void fgl_andrej_F20 ();

  void fgl_andrej_F28 ();

  void fgl_andrej_F36 ();

  void fgl_andrej_F37 ();

  void fgl_andrej_F61 ();

  void fgl_andrej_F81 ();

  void fgl_andrej_F84 ();

  void fgl_andrej_fabatupd ();

  void fgl_andrej_FGL ();

  void fgl_andrej_FP1 ();

  void fgl_andrej_FP2 ();

  void fgl_andrej_G21 ();

  void fgl_andrej_G21a ();

  void fgl_andrej_G22 ();

  void fgl_andrej_G27 ();

  void fgl_andrej_G27a ();

  void fgl_andrej_G28 ();

  void fgl_andrej_G29 ();

  void fgl_andrej_G2R ();

  void fgl_andrej_G33 ();

  void fgl_andrej_GA8 ();

  void fgl_andrej_GB1 ();

  void fgl_andrej_GB8 ();

  void fgl_andrej_GC1 ();

  void fgl_andrej_GC1a ();

  void fgl_andrej_GC2 ();

  void fgl_andrej_GC3 ();

  void fgl_andrej_GC5 ();

  void fgl_andrej_GCEb ();

  void fgl_andrej_GCEd ();

  void fgl_andrej_GCEe ();

  void fgl_andrej_GCP ();

  void fgl_andrej_GRH ();

  void fgl_andrej_GRI ();

  void fgl_andrej_GRJ ();

  void fgl_andrej_GS1 ();

  void fgl_andrej_GW1c ();

  void fgl_andrej_GW1d ();

  void fgl_andrej_GW3 ();

  void fgl_andrej_GW3a ();

  void fgl_andrej_GW3b ();

  void fgl_andrej_GW3c ();

  void fgl_andrej_GW3d ();

  void fgl_andrej_GW3e ();

  void fgl_andrej_GW3f ();

  void fgl_andrej_GW3g ();

  void fgl_andrej_GW4a ();

  void fgl_andrej_GW6a ();

  void fgl_andrej_GZD ();

  void fgl_andrej_TGW1c ();

  void fgl_andrej_TGW1d ();

  void fgl_andrej_TGW3 ();

  void fgl_andrej_TGW3a ();

  void fgl_andrej_TGW3b ();

  void fgl_andrej_TGW3c ();

  void fgl_andrej_TGW3d ();

  void fgl_andrej_TGW3e ();

  void fgl_andrej_TGW3f ();

  void fgl_andrej_TGW3g ();

  void fgl_andrej_TGW6a ();

  void fgl_andrej_I11 ();

  void fgl_andrej_I19 ();

  void fgl_andrej_I22 ();

  void fgl_andrej_I51 ();

  void fgl_andrej_I51a ();

  void fgl_andrej_I57 ();

  void fgl_andrej_I5B ();

  void fgl_andrej_I5C ();

  void fgl_andrej_I5D ();

  void fgl_andrej_I5T ();

  void fgl_andrej_IA ();

  void fgl_andrej_IAE ();

  void fgl_andrej_IAF ();

  void fgl_andrej_IAG ();

  void fgl_andrej_IB ();

  void fgl_andrej_IB3 ();

  void fgl_andrej_IBS ();

  void fgl_andrej_IBT ();

  void fgl_andrej_IC1 ();

  void fgl_andrej_IC2 ();

  void fgl_andrej_IC3 ();

  void fgl_andrej_IC5 ();

  void fgl_andrej_ICG ();

  void fgl_andrej_ID8 ();

  void fgl_andrej_IR ();

  void fgl_andrej_IR2 ();

  void fgl_andrej_IS2 ();

  void fgl_andrej_IS3 ();

  void fgl_andrej_IS9 ();

  void fgl_andrej_ISM ();

  void fgl_andrej_ISV ();

  void fgl_andrej_IT3 ();

  void fgl_andrej_IU1 ();

  void fgl_andrej_J15 ();

  void fgl_andrej_J18 ();

  void fgl_andrej_J27a ();

  void fgl_andrej_J31 ();

  void fgl_andrej_J31a ();

  void fgl_andrej_J31glob ();

  void fgl_andrej_J34 ();

  void fgl_andrej_J36 ();

  void fgl_andrej_J36a ();

  void fgl_andrej_J36b ();

  void fgl_andrej_J36c ();

  void fgl_andrej_J36e ();

  void fgl_andrej_J36f ();

  void fgl_andrej_J36g ();

  void fgl_andrej_J38 ();

  void fgl_andrej_J38a ();

  void fgl_andrej_JC2g ();

  void fgl_andrej_J3C ();

  void fgl_andrej_J51 ();

  void fgl_andrej_J54 ();

  void fgl_andrej_J55 ();

  void fgl_andrej_J77a ();

  void fgl_andrej_J91 ();

  void fgl_andrej_JA1g ();

  void fgl_andrej_JA3g ();

  void fgl_andrej_JA5g ();

  void fgl_andrej_JC1 ();

  void fgl_andrej_JC1a ();

  void fgl_andrej_JC1b ();

  void fgl_andrej_JC1d ();

  void fgl_andrej_JC1e ();

  void fgl_andrej_JC1f ();

  void fgl_andrej_JC1g ();

  void fgl_andrej_JC2 ();

  void fgl_andrej_JC2a ();

  void fgl_andrej_JC2b ();

  void fgl_andrej_JC2d ();

  void fgl_andrej_JC2e ();

  void fgl_andrej_JC2f ();

  void fgl_andrej_JR1 ();

  void fgl_andrej_JR5 ();

  void fgl_andrej_JR6 ();

  void fgl_andrej_JR7 ();

  void fgl_andrej_JR8 ();

  void fgl_andrej_JRB ();

  void fgl_andrej_JRH ();

  void fgl_andrej_JRI ();

  void fgl_andrej_JRM ();

  void fgl_andrej_JRN ();

  void fgl_andrej_JRO ();

  void fgl_andrej_JRS ();

  void fgl_andrej_JS1 ();

  void fgl_andrej_JS4c ();

  void fgl_andrej_L11 ();

  void fgl_andrej_L11a ();

  void fgl_andrej_L11b ();

  void fgl_andrej_L11c ();

  void fgl_andrej_L11e ();

  void fgl_andrej_L11f ();

  void fgl_andrej_L11g ();

  void fgl_andrej_L11i ();

  void fgl_andrej_L11j ();

  void fgl_andrej_L14 ();

  void fgl_andrej_L14a ();

  void fgl_andrej_L51 ();

  void fgl_andrej_L51a ();

  void fgl_andrej_L51b ();

  void fgl_andrej_L51c ();

  void fgl_andrej_L51d ();

  void fgl_andrej_L51e ();

  void fgl_andrej_L51f ();

  void fgl_andrej_L54 ();

  void fgl_andrej_L54a ();

  void fgl_andrej_L61 ();

  void fgl_andrej_L61a ();

  void fgl_andrej_L61b ();

  void fgl_andrej_L61c ();

  void fgl_andrej_L61d ();

  void fgl_andrej_L61e ();

  void fgl_andrej_L61f ();

  void fgl_andrej_L64 ();

  void fgl_andrej_L64a ();

  void fgl_andrej_lcjrintf ();

  void fgl_andrej_M12 ();

  void fgl_andrej_M1A ();

  void fgl_andrej_M27 ();

  void fgl_andrej_M28 ();

  void fgl_andrej_M35 ();

  void fgl_andrej_M41 ();

  void fgl_andrej_M45 ();

  void fgl_andrej_M47 ();

  void fgl_andrej_M51a ();

  void fgl_andrej_M53 ();

  void fgl_andrej_M53a ();

  void fgl_andrej_M55 ();

  void fgl_andrej_M56 ();

  void fgl_andrej_M57 ();

  void fgl_andrej_M63 ();

  void fgl_andrej_M74 ();

  void fgl_andrej_M82 ();

  void fgl_andrej_MS3_20 ();

  void fgl_andrej_MZ8 ();

  void fgl_andrej_MZP ();

  void fgl_andrej_R17 ();

  void fgl_andrej_R21 ();

  void fgl_andrej_R21a ();

  void fgl_andrej_R21b ();

  void fgl_andrej_R21c ();

  void fgl_andrej_R21d ();

  void fgl_andrej_RAE ();

  void fgl_andrej_RAF ();

  void fgl_andrej_RS1c ();

  void fgl_andrej_Q11h ();

  void fgl_andrej_QA1 ();

  void fgl_andrej_QA5 ();

  void fgl_andrej_N11f ();

  void fgl_andrej_N31 ();

  void fgl_andrej_N41b ();

  void fgl_andrej_K11e ();

  void fgl_andrej_K41 ();

  void fgl_andrej_K41a ();

  void fgl_andrej_K41b ();

  void fgl_andrej_K41c ();

  void fgl_andrej_K41d ();

  void fgl_andrej_K41e ();

  void fgl_andrej_K47 ();

  void fgl_andrej_K47a ();

  void fgl_andrej_KL1a ();

  void fgl_andrej_KL2a ();

  void fgl_andrej_KS2 ();

  void fgl_andrej_xx ();

  void fgl_andrej_yy ();

  void setUp();
  void tearDown();
};

#endif
