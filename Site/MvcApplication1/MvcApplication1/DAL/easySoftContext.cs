using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;
using GameWebSite.Models;

namespace GameWebSite.DAL
{
    public class easySoftContext : DbContext
    {
        public easySoftContext()
            : base("easySoftEntities")
        { }

        public DbSet<User> Users { get; set; }
        public DbSet<Download> Downloads { get; set; }
        public DbSet<Tag> Tags { get; set; }
        public DbSet<TagOriginal> TagsOriginais { get; set; }

        public DbSet<Ligacao> Ligacoes { get; set; }
        public DbSet<Ligacao_Tag> Ligacao_Tag { get; set; }
        public DbSet<User_Tag> User_Tag { get; set; }
        public DbSet<Estado_Humor> EstadoDeHumor { get; set; }
        public DbSet<EstadoDeLigacao> EstadoDeLigacao { get; set; }
    }
}