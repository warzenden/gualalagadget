/*
 * 
 * 
 *
 */


  
      	function parseURL(s) {
      		
      	    var sPageURL = window.location.search.substring(1);
      	    var sURLVariables = sPageURL.split('&');
      	    
      	  for (var i = 0; i < sURLVariables.length; i++)
          {

              var sParameterName = sURLVariables[i].split('=');
              if (sParameterName[0] == s)
              {	
            	  
                  return sParameterName[1];
              }
          }
      	    
      	}
      	
        var altText = "None";
        var ggFootprint = "100 X 110 mm";
        var ggHeight = "80 mm";
        var ggTracks = "1";
        var ggBearings = "10";
        var ggBandW = "20 ball/min";
        var ggLatency = "2 sec";
        var ggSolar = "Yes";
      	
       
        function setPageValues() {
        
        	var id = parseURL('gId');

        	
        	var imgURL = "/assets/img/gg_sm.png";
        	
        
        
		switch(id) {	
		case "0":
			//coaxial_sm
			altText = "Coaxial";
			imgURL = "/assets/img/coaxial_sm.png";
	        
	        ggFootprint = "70 X 70 mm";		ggHeight = "96 mm";		ggTracks = "2";
	        ggBearings = "10";				ggBandW = "37 ball/min";
	        ggLatency = "12 sec";				ggSolar = "Yes";
			
			break;
		case "1": 
			//archimedes_sm
			altText = "Archimedes";
			imgURL = "/assets/img/archimedes_sm.png";
			
	        ggFootprint = "102 X 102 mm";		ggHeight = "136 mm";		ggTracks = "2";
	        ggBearings = "26";				ggBandW = "32 ball/min";
	        ggLatency = "50 sec";				ggSolar = "Yes";
			
			break;
		case "2":
			//big_gear_sm
			altText = "Big Gear";
			imgURL = "/assets/img/big_gear_sm.png";
			
	        ggFootprint = "120 X 126 mm";		ggHeight = "132 mm";		ggTracks = "3";
	        ggBearings = "30";				ggBandW = "120 ball/min";
	        ggLatency = "16 sec";				ggSolar = "Yes";
			
			
			break;
		case "3": 
			//comb_sm
			altText = "Comb";
			imgURL = "/assets/img/comb_sm.png";
			
	        ggFootprint = "65 X 70 mm";		ggHeight = "95 mm";		ggTracks = "1";
	        ggBearings = "17";				ggBandW = "17 ball/min";
	        ggLatency = "29 sec";				ggSolar = "Yes";
			
			
			break;
		case "4":
			//magnetic_sm
			altText = "Magnetic";
			imgURL = "/assets/img/magnetic_sm.png";
			
	        ggFootprint = "53 X 103 mm";		ggHeight = "92 mm";		ggTracks = "1";
	        ggBearings = "1";				ggBandW = "1.2 ball/min";
	        ggLatency = "50 sec";				ggSolar = "Yes";
			
			
			break;
		case "5": 
			//manual
			altText = "Manual";
			imgURL = "/assets/img/manual_sm.png";
			
	        ggFootprint = "70 X 70 mm";		ggHeight = "96 mm";		ggTracks = "2";
	        ggBearings = "10";				
	        ggBandW = "37 ball/min";
	        ggLatency = "12 sec";				ggSolar = "Yes";
			
			break;
			
		case "6":
			//piston_sm
			altText = "Piston";
			imgURL = "/assets/img/piston_sm.png";
			
	        ggFootprint = "55 X 102 mm";		ggHeight = "125 mm";		ggTracks = "1";
	        ggBearings = "14";				ggBandW = "46";
	        ggLatency = "17";				ggSolar = "Yes";
			
			break;
		case "7": 
			//small_gear_sm
			altText = "Small Gear";
			imgURL = "/assets/img/small_gear_sm.png";
			
	        ggFootprint = "90 X 92 mm";		ggHeight = "96 mm";		ggTracks = "2";
	        ggBearings = "10";				ggBandW = "37 ball/min";
	        ggLatency = "12 sec";				ggSolar = "Yes";
			
			break;
		default:
			altText = "No Id found";

		}        	
              
		var spectext = "FootPrint: " + ggFootprint + " Height: " + ggHeight + "<br>"; 
		spectext = spectext + "Tracks: " + ggTracks + " Bearings: " + ggBearings + "<br>";  
		spectext = spectext + "Bandwidth: " + ggBandW + " Latency: " + ggLatency + "<br>"; 
		spectext = spectext + "Solar: " + ggSolar; 
		gadSpec.innerHTML = spectext;
		
        gadImage.src = imgURL
        gadImage.alt = altText;
        ggTitle.innerHTML = altText;
        gadName.value = altText;
        
        }




