{:average=>[
{:title=>"test", :avg_effectiveness=>2.92, :avg_effectiveness_surveys=>13},
{:title=>"test2", :avg_effectiveness=>0.67, :avg_effectiveness_surveys=>3}, 
{:title=>"test3", :avg_effectiveness=>3.0, :avg_effectiveness_surveys=>2},
{:title=>"test4", :avg_effectiveness=>3.0, :avg_effectiveness_surveys=>1},
{:title=>"test5", :avg_effectiveness=>0.0, :avg_effectiveness_surveys=>1}, 
{:title=>"test6", :avg_effectiveness=>1.0, :avg_effectiveness_surveys=>1}, 
{:title=>" test7", :avg_effectiveness=>1.0, :avg_effectiveness_surveys=>1}, 
{:title=>"test8",  :avg_effectiveness=>2.0, :avg_effectiveness_surveys=>1}, 
{:title=>"test9", :avg_effectiveness=>3.0, :avg_effectiveness_surveys=>1}, 
{:title=>"test10",  :avg_effectiveness=>2.0, :avg_effectiveness_surveys=>1}
]
}

------------- i am sorting them using -----------------------

 data = data.sort { |x, y| y[:avg_effectiveness_surveys] <=> x[:avg_effectiveness_surveys] }
-----------------------------------------------------------------------------------------------------------

Problem:

I would like to find that if avg_effectiveness_surveys => values are similar e.g. :avg_effectiveness_surveys=>1. Then I would like to sort them basis of :avg_effectiveness too. e.g.  


{:average=>[
{:title=>"test",  :avg_effectiveness=>2.92, :avg_effectiveness_surveys=>13},
{:title=>"test2", :avg_effectiveness=>0.67, :avg_effectiveness_surveys=>3}, 
{:title=>"test3", :avg_effectiveness=>3.0, :avg_effectiveness_surveys=>2},
{:title=>"test9", :avg_effectiveness=>3.0, :avg_effectiveness_surveys=>1},
{:title=>"test4", :avg_effectiveness=>3.0, :avg_effectiveness_surveys=>1},
{:title=>"test8",  :avg_effectiveness=>2.0, :avg_effectiveness_surveys=>1}, 
{:title=>"test10",  :avg_effectiveness=>2.0, :avg_effectiveness_surveys=>1}, 
{:title=>"test6", :avg_effectiveness=>1.0, :avg_effectiveness_surveys=>1}, 
{:title=>" test7", :avg_effectiveness=>1.0, :avg_effectiveness_surveys=>1}, 
{:title=>"test5", :avg_effectiveness=>0.0, :avg_effectiveness_surveys=>1}
]
}
