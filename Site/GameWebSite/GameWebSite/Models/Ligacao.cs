using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class Ligacao
    {
        
        private int LigacaoID { get; set; }
        private int User1ID { get; set; }
        private int User2ID { get; set; }
        private int Força { get; set; }
        private DateTime DataDeInicio { get; set; }
        private int EstadoDaLigacaoID { get; set; }
    }
}