print.o : print.cpp print.h struct.h
	g++ -c $<
display_options.o : display_options.cpp display_options.h struct.h
	g++ -c $<
sort.o : sort.cpp sort.h struct.h
	g++ -c $<
add_file.o : add/add_file.cpp add/add_file.h add/struct.h
	g++ -c $<
add_manual.o : add/add_manual.cpp add/add_manual.h add/struct.h
	g++ -c $<
add_currency.o : add/add_currency.cpp add/add_currency.h add/struct.h
	g++ -c $<
add.o : add/add.cpp add/add.h add_file.o add_manual.o add_currency.o
	g++ -c $<
edit.o : edit/edit.cpp edit/edit.h edit/struct.h
	g++ -c $<
remove.o : remove/remove.cpp remove/remove.h remove/struct.h
	g++ -c $<
display_options_search.o : search/display_options_search.cpp search/display_options_search.h search/struct.h
	g++ -c $<
search_category.o : search/search_category.cpp search/search_category.h search/struct.h
	g++ -c $<
search_date.o : search/search_date.cpp search/search_date.h search/struct.h
	g++ -c $<
search_income_expense.o : search/search_income_expense.cpp search/search_income_expense.h search/struct.h
	g++ -c $<
search.o : search/search.cpp search/search.h display_options_search.o search_category.o search_date.o search_income_expense.o
	g++ -c $<
change_username.o : settings/change_username.cpp settings/change_username.h
	g++ -c $<
currency_converter.o : settings/currency_converter.cpp settings/currency_converter.h
	g++ -c $<
settings.o : settings/settings.cpp settings/settings.h change_username.o currency_converter.o
	g++ -c $<
stat_monthly.o : statistics/stat_monthly.cpp statistics/stat_monthly.h
	g++ -c $<
stat_yearly.o : statistics/stat_yearly.cpp statistics/stat_yearly.h
	g++ -c $<
statistic.o : statistics/statistic.cpp statistics/statistic.h stat_monthly.o stat_yearly.o
	g++ -c $<
main.o : main.cpp
	g++ -c $<
program : print.o sort.o display_options.o add_file.o add_manual.o add_currency.o add.o edit.o remove.o display_options_search.o search_date.o search_category.o search_income_expense.o search.o change_username.o currency_converter.o settings.o stat_monthly.o stat_yearly.o statistic.o main.o
	g++ $^ -o $@
remove :
	rm *.exe | rm *.o
.PHONY : remove
